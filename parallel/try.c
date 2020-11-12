#include <stdio.h>

int a[100];

int main() {
    int i;
    int b[100], c[100];
    
    #pragma omp parallel private(i)
    { //並列領域開始
        for( i = 0; i < 100; i++ ) {
            a[i] = b[i] = c [i] = 0;
        }
        b[0] = a[0];
    } //並列領域開始
}
