#include <stdio.h>

#define N 4

double fn(double, double* , int);

int main() {
    
    double a[] = {1,2,3,4,5};
    
    printf("%f\n",fn(2,a,N));
    
    return 0;
}

double fn(double x, double a[], int i) {
        if( i == 0 ) {
            return a[N];
        } else {
            return fn(x,a,i-1)*x + a[N-i];
        }
}
