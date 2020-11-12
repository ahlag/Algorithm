#include <iostream>
#include <sys/time.h>

using namespace std;

/*

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}
*/

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return ( tval.tv_sec );
}

int main () {
    
    double current = get_current_time();
    
    cout << current << endl;
    
    return 0;
}
