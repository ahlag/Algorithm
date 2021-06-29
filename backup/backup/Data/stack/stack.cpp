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

int push( int x ) {
    if( isFull() ) {
        cout << "Stack full! Overflow" << endl;
        exit(1); //Overflow
    } else {
        top++;
        S[top] = x;
        return x;
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

int main () {
    
    initialize();
    
    fstream file;
    string buf;
    
    file.open("input.txt", ios::in);
    if(!file.is_open()) {
        exit(3);
    }
    
    getline(file,buf);
    stringstream ss1(buf);
    
    char s[N] = {};
    int a = 0, b = 0, c = 0;
    int i = 0, cnt = 0;
    
    while( ss1 >> s[i] ) {
        i++;
        cnt++;
    }
    
    cout << "cnt = " << cnt << endl;
    
    for( i = 0; i < cnt; i++ ) {
        cout << s[i] << endl;
    }
    
    int v = 0;
    char str[1];
    
    for( i = 0; i < cnt; i++ ) {
        if( s[i] == '+' ) {
            a = pop();
            b = pop();
            push( a + b );
        } else if ( s[i] == '-' ) {
            b = pop();
            a = pop();
            push( a - b );
        } else if (s[i] == '*' ) {
            a = pop();
            b = pop();
            push( a * b );
        } else {
            str[0] = s[i];
            v = atoi(str);
            push(v);
        }
    }
    
    cout << pop() << endl;
    
    file.close();
    
    return 0;
}
