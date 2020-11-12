#include <iostream>
#include <cstream>

double myexp(double);

void main(void) {
    
    double x;
    
    cout << "        x               myexp(x)            exp(x)" << endl;
    
    for( int i = 0; i <= 40; i+=10 ) {
        cout << x << "\t" << myexp(x) << "\t" << exp(x) <, endl;
    }
}

double myexp(double x) {
    double EPS = 1E-08;
    double s = 1.0, e = 1.0, d;
    int k;
    
    for( k = 1; k <= 200; k++ ) {
        d = s;
        e = e * x/k;
        s = s + e;
        if( fabs(s-d) < EPS*fabs(d) )
            return s;
    }
    return 0.0;
}
