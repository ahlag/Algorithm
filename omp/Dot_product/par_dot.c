#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#ifdef _OPENMP
#include <omp.h>

void mxv(int m, int n, double * restrict a,
         double * restrict b, double * restrict c);

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

int main(int argc, char *argv[]) {
    double *a,*b,*c;
    int i, j, m, n;

    printf("Please give m and n: ");
    scanf("%d %d",&m,&n);

    if ( (a=(double *)malloc(m*sizeof(double))) == NULL )
        perror("memory allocation for a");
    if ( (b=(double *)malloc(m*n*sizeof(double))) == NULL )
        perror("memory allocation for b");
    if ( (c=(double *)malloc(n*sizeof(double))) == NULL )
        perror("memory allocation for c");

    printf("Initializing matrix B and vector c\n");
    for (j=0; j<n; j++)
        c[j] = 2.0;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            b[i*n+j] = i;
    
    printf("Executing mxv function for m = %d n = %d\n",m,n);
    double beg = get_current_time();
    (void) mxv(m, n, a, b, c);
    printf("Elapsed time : %f\n", get_current_time() - beg);

    free(a);free(b);free(c);
    return(0);
}

void mxv(int m, int n, double * restrict a,
         double * restrict b, double * restrict c) {
    int i, j;
    
#pragma omp parallel for default(none) \
        shared(m,n,a,b,c) private(i,j)
    for (i=0; i<m; i++) {
        a[i] = 0.0;
        for (j=0; j<n; j++)
            a[i] += b[i*n+j]*c[j];
    } /*-- End of omp parallel for --*/
    
    for(i=0; i<m; i++)
        printf("a[%d] = %f\n",i, a[i]);
}
