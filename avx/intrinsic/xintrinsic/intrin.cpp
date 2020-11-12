#include <iostream>
#include <xmmintrin.h>

using namespace std;

int main() {
    
    __m128 a = {1.0f, 2.0f, 3.0f, 4.0f};
    __m128 b = {1.1f, 2.1f, 3.1f, 4.1f};
    float c[4];
    
    __m128 ps = _mm_add_ps(a,b); //add
    
    _mm_storeu_ps(c,ps); //store
    
    for( int i = 0; i < 4; i++ ) {
        cout << c[i] << " ";
    }
    cout << endl;
    
    return 0;
}
