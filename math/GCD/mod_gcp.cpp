#include <iostream>
#include <cmath>

using namespace std;

int gcd(int, int);

int main() {
    
    cout << "gcd(24,18) = " << gcd(24,18) << endl;
    cout << "gcd(1071,1029) = " << gcd(1071,1029) << endl;
    
    return 0;
}

int gcd(int m, int n) {
    if( n == 0 ) {
        return m;
    } else {
        return gcd(n, m%n);
    }
}
