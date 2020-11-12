#include <iostream>

using namespace std;

double factorial(int i) {
    if( i > 1  ) {
        return i*factorial(i-1);
    } else {
        return 1;
    }
}

int main () {

    cout << "Input x! : " << endl;
    double i = 0.0;
    cin >> i;

    cout << factorial(i) << endl;
    
}
