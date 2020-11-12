#include <iostream>
#include <cerrno>

using namespace std;

int main( ) {
    
    cout << "Please enter expression (we can handle +, –, *, and /)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    
    int lval = 0;
    int rval;
    cin >> lval;
    
    if(!cin) cerr << "no first operand" << endl;
    
    for(char op; cin >> op;) {
        if (op != 'x') cin>>rval;
        if (!cin) cerr << "no second operand" << endl;
        switch(op) {
            case '+':
                lval += rval; // add: lval = lval + rval
                break;
            case '-':
                lval -= rval; // subtract: lval = lval – rval
                break;
            case '*':
                lval *= rval; // multiply: lval = lval * rval
                break;
            case '/':
                lval /= rval; // divide: lval = lval / rval
                break;
            default: // not another operator: print result
                cout << "Result: " << lval << '\n';
                return 0;
        }
    }
        cerr << "bad expression" << endl;
    
    return 0;
}
