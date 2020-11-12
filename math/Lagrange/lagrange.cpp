#include <iostream>

using namespace std;

double lagrange(double *, double *, int , double);

int main() {
    
    double x[] = {0.0,1.0,3.0,6.0,7.0},
           y[]={0.8,3.1,4.5,3.9,2.8};
    
    double t;
    
    int n = sizeof(x)/sizeof(x[0]);
    
    cout << "      x      y" << endl;
    
    for( t = 0.0; t <= 7.0; t += 0.5) {
        cout << t << "  " << lagrange(x,y,n,t) << endl;
    }
    
    return 0;
}

double lagrange( double x[], double y[], int n, double t) {
    
    double div = 0.0, coef = 0.0, sum = 0.0;
    
    for(int i = 0; i < n; i++) {
        coef = y[i];
        for(int j = 0; j < n; j++) {
            if( i!= j )
                coef = coef*(t - x[j]) / (x[i] - x[j]);
            
        }
        sum = sum + coef;
    }
    
    return sum;
}
