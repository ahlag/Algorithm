#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    
    fstream file;
    string buf;
    int N = 0;
    int v = 0;
    int minj = 0;
    int i, j, k;
    int cnt = 0;
    
    file.open("input.txt", ios::in);
    if(!file.is_open()) {
        return EXIT_FAILURE;
    }
    
    getline(file,buf);
    stringstream ss1(buf);
    ss1 >> N;
    
    getline(file,buf);
    stringstream ss2(buf);
    
    int *A  = new int[N];
    
    for( i = 0 ; i < N ; i++ ) {
        ss2 >> A[i];
    }
    
    for( i = 0; i < N ; i++ ) {
        minj = i;
        for( j = i; j < N; j++ ) {
            if( A[j] < A[minj] ) {
                minj = j;
            }
        }
        swap(A[i],A[minj]);
        
        for( k = 0; k < N; k++ ) {
            cout << A[k] << " ";
        }
        cout << endl;
        
        if( i != minj ) {
            cnt++;
        }
    }
    
    for( i = 0; i < N; i++ ) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << cnt << endl;
    
    delete[] A;
    
    file.close();
    
    return 0;
}
