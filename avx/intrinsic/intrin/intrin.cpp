#include <iostream>
#include <immintrin.h>

using namespace std;

int main() {
    
    __m256 a = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
    __m256 b = {1.1f, 2.1f, 3.1f, 4.1f, 5.1f, 6.1f, 7.1f, 8.1f};
    float c[8];
    
    asm("vmovaps (%0), %%ymm0"::"r"(a));
    //asm("vaddps  (%0), %%ymm0"::"r"(b));
    //asm("vmovaps (%0), %%ymm0"::"r"(c));
    
    //__m256 ps = _mm256_add_ps(a,b); //add
    //_mm256_storeu_ps(c,ps); //store
    
    for( int i = 0; i < 8; i++ ) {
        cout << c[i] << " ";
    }
    cout << endl;
    
    return 0;
}
