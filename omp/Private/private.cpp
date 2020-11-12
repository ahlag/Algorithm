#include <iostream>
#include <omp.h>

#define N 100
#define PARALLEL

int a[N], b[N], c[N];

using namespace std;

int main () {
    
    int i,j,k;
    int dtemp = 2;
    double dts, dte;
    
    for(i=0;i<N;i++) {
        a[i] = i;
        c[i] = i+1;
    }
    dts = omp_get_wtime();
    
#pragma omp parallel for private(dtemp,j)
    for(i = 0; i < N; i++) {
        dtemp = b[i];
        for(j = 0; j < N; j++) {
            a[j] += dtemp*c[j];
        }
    }
    
    dte = omp_get_wtime();
    
    for(i=0;i<N;i++)
        cout << "a[" << i << "] = " << a[i] << endl;
    
    cout << "Elapsed time : " << dte - dts << endl;
    
    return 0;
}
