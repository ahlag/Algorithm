#include <iostream>
#include <cmath>

using namespace std;

double func(double a);

int main() {
    
    double a = 30.0;
    cout << "The value of sin(" << a << ") = is " << func(a) << "." << endl;
    
    return 0;
}
