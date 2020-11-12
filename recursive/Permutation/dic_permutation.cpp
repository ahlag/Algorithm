#include <iostream>
#include <vector>

#define N 4

using namespace std;

vector<int> b(N+1);

void perm(int);

int main() {
    for( int i = 1; i <= N; i++) //Initialization
        b[i] = i;
    perm(1);

    return 0;
}

void perm(int i) {
    
    int j,k;
    int tmp;
    
    if( i < N ) {
        for(j=i;j<=N;j++) {
            tmp = b[j];         //Rotate p[i]~p[j] to the left
            for(k=j;k>i;k--) {
                b[k] = b[k-1];
            }
            b[i] = tmp;
            
            perm(i+1);          //Recursive call
            
            for(k=i;k<j;k++) {      //Return arrays to the original position before
                                    //recursive call
                b[k] = b[k+1];
            }
            b[j] = tmp;
        }
    } else {
        for(j=1;j<=N;j++)
            cout << b[j] << "  ";
        cout << endl;
    }
    
    
    
}
