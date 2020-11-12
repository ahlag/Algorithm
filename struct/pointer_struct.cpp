#include <iostream>
#include <string>

#define N 2

using namespace std;

typedef struct complex {
    double real;
    double img;
} complex_t;

int main() {
    complex_t a={2.5,3.2}, *p;
    
    p = &a;
    cout << (*p).real << "+" << (*p).img << "i" << endl;
    
    p->real = 10.2;
    p->img =   7.5;
    
    cout << p->real << "+" << p->img << "i" << endl;
    cout <<   a.real << "+" << a.img << "i" << endl;
    
    return 0;
}
