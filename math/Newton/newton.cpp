#include <iostream>
#include <cmath>
#include <ctime>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)

const double EPS = 1E-08;
const int N = 1000;

using namespace std;

double random_number() {
    srand(time(nullptr));
    double random_variable = rand();
    
    random_variable = fmod(random_variable,10.0);
    return random_variable;
}

int main() {
    
    double x = random_number(), dx = 0.0;
    int i = 0;
    
    for( i = 0; i < N; i++ ) {
        dx = x;
        
        x = x - f(x)/g(x);
        
        cout << "i = " << i << endl;

        if( fabs(x - dx) < EPS*fabs(dx)) {
            cout << "The root is :" << x << endl;
            break;
        }
    }
    
    if( i >= N ) {
        cout << "Limit reached. Unable to converge." << endl;
    }
    
    return 0;
}
