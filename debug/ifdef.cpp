#include <iostream>

#define DEBUG_W
#define DEBUG 2

using namespace std;

int main() {
    #if   DEBUG == 1
        cout << "If DEBUG == 1, only this part is compiled" << endl;
    #elif DEBUG == 2
        cout << "If DEBUG == 2, only this part is compiled" << endl;
    #else
        cout << "DEBUG != 1,2; only this part is compiled" << endl;
    #endif
    
    #ifdef DEBUG_W
        cout << "If DEBUD_W is defined, only this part is compiled." << endl;
    #else
        cout << "If DEBUD_W is not defined, only this part is compiled." << endl;
    #endif
    
    return 0;
}
