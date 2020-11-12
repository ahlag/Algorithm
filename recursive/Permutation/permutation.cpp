#include <iostream>
#include <vector>

#define N 4

using namespace std;

vector<int> b(N);

void perm(int i);

int main() {
    int i;
    
    for (i=1;i<=N;i++)
        b[i]=i;
    
    perm(1);
    
    return 0;
}

void perm(int i) {
    int j, tmp;
    if( i < N ) {
        for(j = i; j <= N; j++ ) {
            tmp = b[i]; b[i] = b[j]; b[j] = tmp;
            perm(i+1);
            tmp = b[i]; b[i] = b[j]; b[j] = tmp;
        }
    } else {
        for(j = 1; j <= N; j++)
            cout << b[j] << " ";
        cout << endl;
    }
};
