#include <iostream>

using namespace std;

int fib(int n) {
    if( n == 1 || n == 2 ) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
};

int main(int argc, char* argv[]) {
 
    cout << "Enter a number for fibonacci number : " << endl;
    
    int n;
    
    cin >> n;
    
    cout << "fibonacci number of " << n << " is : " <<  fib(n) << endl;
    
    return 0;
}
