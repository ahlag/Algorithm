#include <iostream>

int ga = 100;

void func();

using namespace std;

int main() {
    
    int a = 0;
    
    func(); func(); func();
    cout << "ga = " << ga << " a = " << a << endl;
    
    return 0;
}

void func() {
    int a = 0;
    static int b = 10;
    a++; b++; ga++;
    cout << "func: ga = " << ga << " a = " << a << " b = " << b << endl;
}
