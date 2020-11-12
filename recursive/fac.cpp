#include <iostream>

using namespace std;

int fact(int n) {
    if( n <= 1 ) {
        return 1;
    } else {
        return n*fact(n-1);
    }
};

int main(int argc, char* argv[]) {
 
    cout << "Enter a number for factorial : " << endl;
    
    int n;
    
    cin >> n;
    
    cout << "factorial of " << n << "is : " <<  fact(n) << endl;
    
    return 0;
}
