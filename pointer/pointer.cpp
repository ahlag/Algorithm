#include <iostream>

using namespace std;

int main(int argv, char* argc[]) {
    
    int x = 100;
    int *p = &x;
    
    cout << "*p = " << *p << " p = " << p << endl;
    
    return 0;
}
