#include <iostream>

extern int ex;
extern int ga;

using namespace std;


void func1() {
    ex++;
    ga++;
    cout << "func: ex = " << ex << " ga = " << ga << endl;
}

