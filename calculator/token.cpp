//#include "std_lib_facilities.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
    :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
    :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    
    switch (ch) {
            //not yet   case ';':    // for "print"
            //not yet   case 'q':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
        default:
            cerr << "Bad token" << endl;
            exit(1);
    }
};

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') {cerr << "')' expected" << endl; exit(2); }
            return d;
        }
        case '8':            // we use '8' to represent a number
            return t.value;  // return the number's value
        default:
            cerr << "primary expected" << endl; exit(2);
    }
}
//------------------------------------------------------------------------------

int main() {
    try {
        while (cin) {
                cout << expression() << '\n';
        }
    }
    catch (exception& e) {
        cerr << e.what() << endl;
            return 1;
        }
    catch (...) {
        cerr << "exception \n";
        return 2;
    }
}
        
//------------------------------------------------------------------------------
double expression() {
    double left = term();      // read and evaluate a Term
    Token t = ts.get();     // get the next token from the token stream
    while(true) {
        switch(t.kind) {
            case '+':
                left += term();    // evaluate Term and add
                t = ts.get();
                break;
            case '-':
                left -= term();    // evaluate Term and subtract
                t = ts.get();
                break;
            default:
                return left;       // finally: no more + or -: return the answer
        }
    }
}
        
//------------------------------------------------------------------------------
double term() {
    double left = primary();
    Token t = ts.get();     // get the next token
        
    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) {cerr << "divide by zero" << endl; exit(3);}
                left /= d;
                t = ts.get();
                break;
            }
            default:
                return left;
        }
    }
}
