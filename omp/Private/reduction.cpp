#include <iostream>
#include <omp.h>

#define N 100

int a[N], b[N], c[N];

using namespace std;

int main () {

    int i, j, k, ib;
    int istart[MAX_THREADS], iend[MAX_THREADS];
    double dtemp, dmax_t[MAX_THREADS];
    
    ib = N / omg_get_max_threads();
    for(k=0; k<omg_get_max_threads(); k++) {
        dmax_t[k] = 0.0;
        istart[k] = ib*k;
        iend[k]   = (k+1) * ib;
    }
    iend[omg_get_max_threads() - 1] = N;
    
    
    
    
    return 0;
}
