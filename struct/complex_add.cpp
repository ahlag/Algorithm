#include <iostream>
#include <string>

#define N 2

using namespace std;

typedef struct complex {
    double real;
    double img;
} complex_t;

complex_t complex_add( complex_t a, complex_t b );

int main() {
    complex_t a = {1.1,2.2}, b = {3.3,4.4}, c;
    
    c = complex_add( a, b );
    
    cout << "(" << a.real << "+" <<  b.real << ")" << " + "
         << "(" << a.img  << "+" <<  b.img  << ")" << "i = "
         << c.real << " + " << c.img << endl;
    
    return 0;
}

complex_t complex_add(complex_t a, complex_t b) {
    complex_t c;
    
    c.real = a.real + b.real;
    c.img  = a.img  + b.img;
    
    return c;
}
