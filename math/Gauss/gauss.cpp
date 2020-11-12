#include <iostream>
#include <cmath>

using namespace std;

int main () {
    
    /*
    float a[] = { 2.0, 3.0,  1.0,  4.0,
                  4.0, 1.0, -3.0, -2.0,
                 -1.0, 2.0,  2.0,  2.0
    };
    */
    float a[3][4] = { 2.0, 3.0,  1.0,  4.0,
                      4.0, 1.0, -3.0, -2.0,
                     -1.0, 2.0,  2.0,  2.0};
    
    //int N = sizeof(a) / sizeof(a[0]);
    float div = 0.0, temp = 0.0, coef = 0.0;
    int i = 0, j = 0, k = 0, n = 0;
    
    for( i = 0; i < 3; i++ ) {
        div = a[i][i];
        for( j = i; j < 4; j++ ) {
            a[i][j] = a[i][j]/div;
        }
        for( k = 0; k < 3; k++ ) {
                if( k != i ) {
                    coef = a[k][i];
                    for( n = i; n < 4; n++ ) {
                        a[k][n] = a[k][n] - coef*a[i][n];
                    }
                }
            }
    }
    
    for( i = 0; i < 3; i++ ) {
            cout << a[i][3] << endl;
    }

    
    return 0;
}
