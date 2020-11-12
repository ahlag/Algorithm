#include <iostream>
#include <cmath>

using namespace std;

static const int MAX = 200000;

int main(int argc, const char * argv[]) {

    int i = 0;
    int R[MAX] = {}, n;
    int max_value = -10000000;
    int min_value = 100;
    
    cin >> n;
    for( i = 0; i < n; i++ )  cin >> R[i];
    
    for( i = 1; i < n; i++ ) {
        max_value = max( max_value,R[i]-min_value );
        min_value = min( R[i-1],R[i] );
    }
    
    cout << max_value << endl;
    
    
    
    return 0;
}
