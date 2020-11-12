#include <iostream>

using namespace std;

int Combi(int n, int r) {
    if( r == 0 || r == n) {
        return 1;
    } else {
        return Combi(n-1,r-1) + Combi(n-1,r);
    }
};

int main(int argc, char* argv[]) {
 
    cout << "Enter two numbers for combination: n, r " << endl;
    
    int n, r;
    
    cin >> n >> r;
    
    cout << "Combination of " << n << "C" << r << " is : " <<  Combi(n,r) << endl;
    
    return 0;
}
