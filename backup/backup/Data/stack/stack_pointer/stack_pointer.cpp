#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;       //Maximum size of stack
int sp = 0;                     //stack pointer
vector<int> stack(MAX_SIZE);    //Stack

bool push(int *n) {
    if( sp < MAX_SIZE ) {
        stack[sp] = *n;
        cout << "Putting in" << endl;
        cout << "stack[" << sp << "] = " << *n << endl;
        sp++;
        return true;
    } else {
        cout << "Stack is full. Current MAX_SIZE: " << MAX_SIZE << endl;
        return false;
    }
}

bool pop(int *n) {
    if( sp > 0 ) {
        sp--;
        *n=stack[sp];
        cout << "Removing" << endl;
        cout << "stack[" << sp << "] = " << *n << endl;
        return true;
    } else {
        cout << "Stack is empty." << endl;
        return false;
    }
}


int main(void) {
    char c;
    int i;
    
    cout << "Stack begins!" << endl;
    
    while(cin >> c) {
        if(c=='i') {
            cout << "Please type a number: ";
            cin >> i;
            push(&i);
        }
        if(c=='o') {
            cout << "Please type a number: ";
            pop(&i);
        }
    }
    
    return 0;
}
