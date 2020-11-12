#include <iostream>
using namespace std;

bool Input(double& n) {
    cin >> n;
    return n >= 0;
}

bool Average() {
    int count;
    double n;
    double avr = 0.0;
    
    for( count = 0; Input(n); ++count) {
        avr += n;
        cout << count << endl;
    }
    if(count == 0) {
        return false;
    }
    
    avr /= count;
    cout << "The average " << avr << endl;
    return true;
}

int main() {
    while(Average()) {
        
    }
}
