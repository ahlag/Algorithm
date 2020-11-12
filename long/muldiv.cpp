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

void lmul(short *, short, short *);
void ldiv(short *, short, short *);
void print(short *);

int main ( int argc, char *argv[] ) {
    
    short a[N+2]={   0,3050,2508,8080,1233},
          c[N+2];
    
    cout << N << endl;
    
    lmul(a,101,c); print(c);
    ldiv(a,200,c); print(c);
    
    return 0;
}

void lmul(short a[], short b, short c[]) {
    short i; long d, cy = 0;
    for(i = N-1; i >= 0 ; i--  ) {
        d = a[i];
        c[i] = (d*b+cy)%10000;
        cy = (d*b+cy)/10000;
    }
}

void ldiv(short a[], short b, short c[]) {
    short i; long d, rem = 0;
    for(i = 0; i < N ; i++) {
        d = a[i];
        c[i] = (d+rem)/b;
        rem = ((d+rem)%b)*10000;
    }
}

void print(short c[]) {
    for(short i = 0; i < N; i++) {
        cout << c[i] << "\t";
    }
    cout << endl;
}
