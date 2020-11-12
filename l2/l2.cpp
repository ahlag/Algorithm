#include <iostream>
#include <fstream>
#include <vector>
#include <sys/time.h>

using namespace std;

#define M 5   //exponent

struct Datapoint {
    double x,y;
};

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

double ipow(double, short);

int main( int argc, char* argv[] ) {
    
    ifstream ist {argv[1]};
    if(!ist) cerr << "No file input! or Not a file!" << endl;
    
    vector<Datapoint> sparse;
    double x, y;
    while(ist >> x >> y) {
        sparse.push_back(Datapoint{x,y});
    }
    
    //Current time
    double current_t = get_current_time();
    
    for( int i = 0; i < sparse.size(); i++ ) {
        cout << "x = " << sparse[i].x << " y = " << sparse[i].y << endl;
    }
    
//--------------------------------------------------------------------------
    //Gauss-Jordan Method
    double a[M+1][M+2] = {}, s[2*M+1] = {}, t[M+1] = {};
    
    int i,j,k,l;
    
    for( i = 0; i <= 2*M; i++ )
        s[i] = 0;
    
    for( i = 0; i <= M; i++)
        t[i] = 0;
    
    //Calculation of s[] & t[]
    for( i = 0; i < sparse.size(); i++) {
        for( j = 0; j <= 2*M; j++ ) {
            s[j] = s[j] + ipow(sparse[i].x,j);
        }
        for( j = 0; j <= M; j++) {
            t[j] = t[j] + sparse[i].y*ipow(sparse[i].x,j);
        }
    }
    
    //s[] & t[] -> a[][]
    for( i = 0; i <= M; i++ ) {
        for( j = 0; j <= M; j++) {
            a[i][j] = s[i+j];
        }
        a[i][M+1] = t[i];
    }
    
    double div, mul;

    for( i = 0; i <= M; i++ ) {
        div = a[i][i];
        for( j = i; j <= M+1; j++) {
            a[i][j] = a[i][j]/div;
        }
        for( k = 0; k <= M; k++) {
            if( k != i ) {
                mul = a[k][i];
                for( l = 0; l <= M+1; l++ ) {
                    a[k][l] = a[k][l] - mul*a[i][l];
                }
            }
        }
    }

    cout << "    x    y" << endl;
    
    for (double px =-3; px <= 3; px = px+.5 ){
        double p = 0;
        for ( k = 0; k <= M; k++) {
            p = p + a[k][M+1] * ipow(px,k);
        }
        printf("%5.1f   %5.1f\n",px,p);
    }
    
    cout << "Elapsed time : " << get_current_time() - current_t << endl;
    
    return 0;
}

double ipow(double p, short n) {
    double s = 1;
    for( int i = 0; i < n; i++) {
        s = p*s;
    }
    return s;
}


