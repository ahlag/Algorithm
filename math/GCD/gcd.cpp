#include <iostream>

using namespace std;

double gcd(double, double);

int main() {
    
    cout << "gcd(24,18) = " << gcd(24,18) << endl;
    cout << "gcd(1071,1029) = " << gcd(1071,1029) << endl;
    
    return 0;
}

double gcd(double a, double b) {
    if( a == b ) {
        return a;
    } else if ( a > b ) {
        return gcd(a-b,a);
    } else {
        return gcd(a,b-a);
    }
}
