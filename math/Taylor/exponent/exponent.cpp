#include <iostream>
#include <sys/time.h>
#include <cmath>

using namespace std;

const double EPS = 1.0E-8;
const int N = 200;

double factorial(int i) {
    
    if( i > 1  ) {
        return i*factorial(i-1);
    } else {
        return 1;
    }
};

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

int main() {
    
    cout << "Please type a number for x : ";
    
    float x = 0;
    cin >> x;
   
    long double e = 1.0, s = 1.0, d = 0.0;  //Taylor Expansion
    
    double current = get_current_time();
    
    for( int i = 1; i < N; i++ ) {
        d = s;
        
        cout << "Current index i = " << i << endl;
        
        e = e * x/i;
        s = s + e;
        
        cout << "s = " << s << endl;
        cout << "d = " << d << endl;

        //Absolute Value Calculation
        if( fabs(s-d) < EPS*fabs(d) ) {
            if( x > 0 ) {
                cout << "The value of exp(" << x << ") is : " << s << endl;
                cout << "Time elapsed : " << get_current_time() - current << endl;
                return s;
            } else {
                cout << "The value of exp(" << x << ") is : " << s << endl;
                cout << "Time elapsed : " << get_current_time() - current << endl;
                return 1.0/s;
            }
        }
    }
    
    return 0;
}
