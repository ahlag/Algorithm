#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int main() {

    stack<int> S;
    int a, b, x;
    string input;

    while (cin >> input) {
        if ( input[0] == '+') {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a+b);
        }
        else if (input[0] == '-') {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a-b);
        }
        else if (input[0] == '/') {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a/b);
        }
        else if (input[0] == '*') {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a*b);
        }
        else {
            S.push(atoi(input.c_str()));
        }
    }
    cout << S.top() << endl;
    return 0;
}