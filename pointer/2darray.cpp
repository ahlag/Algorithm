#include <iostream>
#include <sys/time.h>

const int N = 3;
const int M = 4;

using namespace std;

void matrix_sum(double a[][M], double b[][M]);

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

int main(int argc, char* argv[]) {
    
    double curt = get_current_time();
    
    cout << "Current calculation time : " << curt << endl;
    
    double a[N][M] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    double b[N][M] = { {1.1,2.2,3.3,4.5}, {5.5,6.6,7.7,8.8}, {10.1,11.1,12.2,13.3} };
    
    matrix_sum(a,b);
    
    cout <<"Elapsed time : " << get_current_time() - curt << endl;
    
    return 0;
}

void matrix_sum(double a[][M], double b[][M]) {
    
    double c[N][M];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            c[i][j] = a[i][j] + b[i][j];
            cout << c[i][j] << "  ";
        }
        cout << endl;
    }
    
}
