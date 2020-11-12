#include <iostream>

#define N 4

using namespace std;

double func(double, double* , int);

int main() {
    
    double a[] = {1,2,3,4,5};
    
    cout << func(2, a, N) << endl;
    
    return 0;
}

double func(double x, double a[], int i) {
        if( i == 0 ) {
            return a[N];
        } else {
            return func(x,a,i-1)*x + a[N-i];
        }
}
