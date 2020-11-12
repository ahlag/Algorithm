#include <iostream>

using namespace std;

int top = 0;
int  S[1000];

void push(int x) {
    S[top++] = x;
}

int pop() {

    return S[--top];

}

int main() {

    int a, b;
    char input;

    while (cin >> input) {
        if ( input == '+') {
            a = pop();
            b = pop();
            push(a+b);
        }
        else if (input == '-') {
            a = pop();
            b = pop();
            push(a-b);
        }
        else if (input == '/') {
            a = pop();
            b = pop();
            push(a/b);
        }
        else if (input == '*') {
            a = pop();
            b = pop();
            push(a*b);
        }
        else {
            push(input - '0');
        }
    }
    cout << pop() << endl;
    return 0;
}