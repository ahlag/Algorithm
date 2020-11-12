#include <iostream>

int ga = 10;

void func();
void func1();

using namespace std;

int main() {
    
    extern int ex;
    func(); func1();
    ex += 50;
    
    ga += 20;
    
    cout << "main: ex = " << ex << " ga = " << ga << endl;
    
    return 0;
}

int ex = 10;

void func() {
    ga += 10; ex += 10;
    cout << "func: ex = " << ex << " ga = " << ga << endl;
}
