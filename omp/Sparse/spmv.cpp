#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

//! == number of maximum dimension of matrix
#define  N      100000

//!== number of maximum number of non-zero elements
#define  NNZ    1000000

//!== number of number of non-zero elements per low
#define  NZPR   8

//!== number of iterations for SpMV
#define  MAX_ITER   100

#define  DEBUG  1
#define  EPS    1.0e-18

/* Please define the matrices in here */
static double  X[N];
static double  Y[N];
static double  VAL[NNZ];
static int     IRP[N+1];
static int     ICOL[NNZ];
static int     ICOL_LIST[N];

void MySpMV(double Y[N],
            int IRP[N+1], int ICOL[NNZ], double VAL[NNZ], double X[N],
            int n, int nnz);

void MySpMV_check(double Y[N],
            int IRP[N+1], int ICOL[NNZ], double VAL[NNZ], double X[N],
            int n, int nnz);

int main(int argc, char* argv[]) {
    
    double  t0, t1, t2, t_w;
    double  dc_inv, d_mflops;
    
    int     i, j, k, kk;
    int     iflag, iflag_t;
    
    
    /* sparse matrix generation --------------------------*/
    srand(1);
    dc_inv = 1.0/(double)RAND_MAX;
    
    k = 0;
    IRP[0] = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            ICOL_LIST[j] = -1;
        }
        for (j=0; j<NZPR; j++) {
        remake:
            kk = (int)((double)N * rand() * dc_inv);
            if (kk == N) kk = N-1;
            if (ICOL_LIST[kk] != -1) {
                goto remake;
            } else {
                ICOL_LIST[kk] = 1;
            }
        }
        for (j=0; j<N; j++) {
            if (ICOL_LIST[j] == 1) {
                ICOL[k] = j;
                VAL[k] = 1.0;
                k ++;
            }
        }
        IRP[i+1] = k;
        X[i] = 1.0;
        Y[i] = 0.0;
    }
    /* end of matrix generation --------------------------*/
    
    /* Start of mat-vec routine ----------------------------*/
    t1 = omp_get_wtime();
    
    for (i=1; i<=MAX_ITER; i++) {
        MySpMV_check(Y, IRP, ICOL, VAL, X, N, NNZ);
    }
    
    t2 = omp_get_wtime();
    t_w =  t2 - t1;
    /* End of mat-vec routine --------------------------- */
    
    
    printf("N  = %d \n",N);
    printf("NNZ  = %d \n",N*NZPR);
    printf("NZPR  = %d \n",NZPR);
    printf("MAX_ITER  = %d \n",MAX_ITER);
    
    
    printf("Mat-Mat time  = %lf [sec.] \n",t_w);
    
    d_mflops = 2.0*(double)N*(double)NZPR*(double)MAX_ITER /t_w;
    d_mflops = d_mflops * 1.0e-6;
    printf(" %lf [MFLOPS] \n", d_mflops);
    
    
    if (DEBUG == 1) {
        /* Verification routine ----------------- */
        iflag = 0;
        for(i=0; i<N; i++) {
            if (fabs(Y[i] - (double)NZPR) > EPS) {
                printf(" Error! in ( %d ) th argument. %lf \n",i, Y[i]);
                iflag = 1;
                break;
            }
        }
        /* ------------------------------------- */
        
        if (iflag == 0) printf(" OK! \n");
        
    }
    
    return 0;
}

void MySpMV_check(double Y[N],
            int IRP[N+1], int ICOL[NNZ], double VAL[NNZ], double X[N],
            int n, int nnz)
{
    
    double  s;
    int     i, j_ptr;
    
    
#pragma omp parallel for private(s,j_ptr)
    for (i=0; i<n; i++) {
        s = 0.0;
        for (j_ptr=IRP[i]; j_ptr <=IRP[i+1]-1; j_ptr++) {
            s += VAL[j_ptr] * X[ICOL[j_ptr]];
        }
        Y[i] = s;
    }
    
    for(i=0;i<n;i++)
        cout << "Y[" << i << "] = " << Y[i] << endl;
}

void MySpMV(double Y[N],
            int IRP[N+1], int ICOL[NNZ], double VAL[NNZ], double X[N],
            int n, int nnz)
{
    double  s;
    int     i, j_ptr;
    
#pragma omp parallel for default(none) \
    private(j_ptr,s) shared(VAL,X,Y,n,ICOL,IRP)
    for (i=0; i<n; i++) {
        s = 0.0;
        for (j_ptr=IRP[i]; j_ptr <=IRP[i+1]-1; j_ptr++) {
            s += VAL[j_ptr] * X[ICOL[j_ptr]];
        }
        Y[i] = s;
    }
    
    for(i=0;i<n;i++)
        cout << "Y[" << i << "] = " << Y[i] << endl;
}
