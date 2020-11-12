#include <iostream>
#include <cmath>
#include "rei_exponent.hpp"

using namespace std;

double factorial(int i) {
    
    if( i > 1  ) {
        return i*factorial(i-1);
    } else {
        return 1;
    }
};

int main() {
    
    cout << EPS << endl;
    
    cout << "Please type a number for x : ";
    
    float x = 0;
    cin >> x;
   
    double d = 0, n1 = 0, d1 = 0, s = 0;  //Taylor Expansion
    double an1 = 0, ad1 = 0, ab = 0;      //Absolute Value Calculation
    
    for( int i = 1; i < N; i++ ) {
        d = s;
        
        cout << "Current index i = " << i << endl;
        n1 = pow(x, i-1);
        cout << "n1 = " << n1 << endl; //
        
        d1 = factorial(i-1);
        cout << "d1 = " << d1 << endl; //
        
        s += n1/d1;
        cout << "s = " << s << endl; //
        cout << "d = " << d << endl; //
        
        an1 = fabs( s-d );
        ad1 = fabs(d);
        ab = an1/ad1;
        
        cout << "ab[" << i << "] = " << ab << endl;
        if( ab < EPS ) break;

    }
    
    cout << "The value of exp(" << x << ") is : " << s << endl;
    
    return 0;
}
