
#include <iostream>
#include <cmath>

using namespace std;

int fact(int);

int main() {
    
    cout << "fact(0) = " << fact(0) << endl;
    cout << "fact(1) = " << fact(1) << endl;
    cout << "fact(2) = " << fact(2) << endl;
    cout << "fact(3) = " << fact(3) << endl;
    cout << "fact(4) = " << fact(4) << endl;
    
    return 0;
}

int fact(int n) {
    
    int p = 1;
    for( int i = 1; i <= n; i++ ) {
        p = p*i;
    }
    return p;
}
