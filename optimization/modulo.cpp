#include <iostream>

using namespace std;

int main() {
    
    int k = -1;
    for( int i = 0; i < 30; i++ ) {
        k = (k + 1) % 12;
        cout << "Before = " << k   << "   "
             << "After  = " << k+1 << endl;
    }
    
    return 0;
}
