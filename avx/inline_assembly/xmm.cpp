#include <iostream>

using namespace std;

int main() {
    
    float a[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b[] = {1.1f, 2.1f, 3.1f, 4.1f};
    float c[4];
    
    asm("movups (%0), %%xmm0"::"r"(a));
    asm("movups (%0), %%xmm1"::"r"(b));
    asm("addps  %%xmm1, %%xmm0":);
    asm("movups %%xmm0, (%0)"::"r"(c));
    
    for( int i = 0; i < 4; i++ ) {
        cout << c[i] << " ";
    }
    cout << endl;
    
    return 0;
}
