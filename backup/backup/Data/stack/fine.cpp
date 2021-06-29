#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int N = 100;
int S[N] = {};
int top;

void initialize( void ) {
    int top = 0;
}

bool isFull( void ) {
    if( top == N ) {
        return true;
    } else return false;
}

bool isEmpty( void ) {
    if( top == 0 ) {
        return true;
    } else return false;
}

void push( int x ) {
    if( isFull() ) {
        cout << "Stack full! Overflow" << endl;
        exit(1); //Overflow
    } else {
        S[++top] = x;
//        cout << S[top] << endl;
    }
}

int pop( ) {
    if( isEmpty() ) {
        cout << "Stack empty! Underflow" << endl;
        exit(2); //Underflow
    } else {
        top--;
        return S[top+1];
    }
}

void read_file( ) {
    fstream file;
    string buf;
    
    file.open("input.txt", ios::in);
    if(!file.is_open()) {
        exit(3);
    }
    
    getline(file,buf);
    stringstream ss1(buf);
    for( int i = 0; i < N; i++) {
        ss1 >> S[i];
        if( S[i] == EOF ) break;
    }
    
    file.close();
}

int main () {
    
    initialize();
    
    int a, b;
    char s[100];
    
    
    
    while( scanf("%s", s) != EOF ) {
        if( s[0] == '+' ) {
            a = pop();
            b = pop();
            push( a + b );
        } else if ( s[0] == '-' ) {
            a = pop();
            b = pop();
            push( a - b );
        } else if (s[0] == '*' ) {
            a = pop();
            b = pop();
            push( a * b );
        } else {
            push(atoi(s));
        }
    }
    
    cout << pop();
    
    return 0;
}
