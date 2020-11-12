#include <iostream>
#include <string>

#define N 2

using namespace std;

typedef struct complex {
    double real;
    double img;
} complex_t;

int main() {
    complex_t a[] = {{1.1,2.2},{3.3,4.4},{5.5,6.6}};
    complex_t *p;
    int i;
    
    p = a;
    for( i = 0; i < 3; i++ ) {
        cout << &((p+i)->real) << '\t' << &((p+i)->img) << endl;
        cout << (p+i)->real << '\t' << (p+i)->img << endl;
    }

    
    return 0;
}
