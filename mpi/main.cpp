#include <iostream>
#include <stdio.h>

using namespace std;

double ran(void) {
    return (double)rand()/(double)RAND_MAX;
}

double calc_pi(int seed, int trial) {
    srand(seed);
    int n = 0;
    for( int i = 0; i < trial ; i++ ) {
        double x = ran();
        double y = ran();
        if( x*x + y*y < 1.0) {
            n++;
        }
    }
    return 4.0*(double)n/(double)trial;
}

int main(int argc, char** argv) {
    double pi = calc_pi(1,1000000);
    cout << "pi : " << pi << endl;

    return 0;
}

