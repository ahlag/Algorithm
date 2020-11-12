#include <iostream>

using namespace std;

int fib(int n) {
    
    int a = 1, b = 1;
    int tmp;
    
    for( int i = 3; i <= n; i++ ) {
        tmp = b;
        b= a + b;
        a = tmp;
    }
    return b;
    
};

int main() {
    cout << "fact(0) = " << fib(0) << endl;
    cout << "fact(1) = " << fib(1) << endl;
    cout << "fact(2) = " << fib(2) << endl;
    cout << "fact(3) = " << fib(3) << endl;
    cout << "fact(4) = " << fib(4) << endl;
    cout << "fact(5) = " << fib(5) << endl;
    
    return 0;
    
}
