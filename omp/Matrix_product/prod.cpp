#include <iostream>
#include <omp.h>

#define  DEBUG  1
#define  EPS    1.0e-18


using namespace std;

int main() {
    
    int i,j,k;
    int N = 3;
    
    int a[N][N], b[N][N], c[N][N];
    int d[N*N] = {1,2,3,4,5,6,7,8,9};
    int e[N*N] = {1,2,3,4,5,6,7,8,9};
    
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            a[i][j] = d[i*N+j];
            b[i][j] = e[i*N+j];
        }
    }
    
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            c[i][j] = 0;
    
#pragma omp parallel for default(none) \
                         private(i,j,k) shared(a,b,c,N)
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) {
                for(k=0;k<N;k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        } /*-- End of parallel for --*/
    
    
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
 //           cout << "a[" << i << "][" << j << "] " << a[i][j] << "*";
 //           cout << "b[" << i << "][" << j << "] " << b[i][j] << "  ";
            cout << "c[" << i << "][" << j << "] = " << c[i][j] << "  ";
        }
        cout << endl;
    }
     
    
    return 0;
}
