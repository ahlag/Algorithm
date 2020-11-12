#include <iostream>
#include <sys/time.h>

#define KETA 20
#define N ((KETA-1)/4+1)

using namespace std;

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

void ladd(short *, short *, short *);
void lsub(short *, short *, short *);
void print(short *);

int main ( int argc, char *argv[] ) {
    
    short a[N+2]={1999,4444,7777,2222,9999},
          b[N+2]={111,6666,3333,8888,1111},
          c[N+2];
    
    cout << N << endl;
    
    ladd(a,b,c); print(c);
    lsub(a,b,c); print(c);
    
    return 0;
}

void ladd(short a[], short b[], short c[]) {
    short i, clast = 0;
    for(i = N-1; i >= 0 ; i--  ) {
        c[i] = a[i] + b[i] + clast;
        if( c[i] > 10000 ) {
            c[i] = c[i] - 1000;
            clast = 1;
        } else {
            clast = 0;
        }
    }
}

void lsub(short a[], short b[], short c[]) {
    short i, brrw = 0;
    for(i = N-1; i >= 0; i--) {
        c[i] = a[i] - b[i] - brrw;
        if( c[i] >= 0 ) {
            brrw = 0;
        } else {
            c[i] = c[i] + 10000;
            brrw = 1;
        }
    }
}

void print(short c[]) {
    for(short i = 0; i < N; i++) {
        cout << c[i] << "\t";
    }
    cout << endl;
}
