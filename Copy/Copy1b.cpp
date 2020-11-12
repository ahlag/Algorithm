#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int cash = 100;

void Play( int bet ) {
    char *C = new char[3];
    C[0] = 'J', C[1] = 'Q', C[2] = 'K';
    printf("Shuffling ...");
    srand(time(NULL)); // seeding random bumber generator
    int i;
    for (i = 0; i < 5; i++ ) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x]; C[x] = C[y]; C[y] = temp;
    }
    int playersGuess;
    printf("What's the position of queen - 1, 2 or 3?");
    cin >> playersGuess;
    if (C[playersGuess-1] == 'Q') {
        cash += 3*bet;
        cout << "You won! You now have " << cash << "." << endl;
    } else {
        cash -= bet;
        cout << "You lost! You now have " << cash << "." << endl;
    }
    delete [] C;
    C = nullptr;
}

int main() {

    int bet;
    while( cash>0 ) {
        printf("What's your bet? $");
        cin >> bet;
        if( bet ==0 || bet > cash ) break;
        Play(bet);
    }
    
    return 0;
}


