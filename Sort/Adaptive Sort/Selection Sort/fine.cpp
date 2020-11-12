#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void trace ( int A[], int N ) {
    
    for( int k = 0; k < N; k++ ) {
        cout << A[k] << " ";
    }
    cout << endl;
}

int selectionSort( int A[], int N ) {
    
    int    i = 0, j = 0, v = 0;
    int  cnt = 0;
    int minj = 0;
    
    for( i = 0; i < N ; i++ ) {
        minj = i;
        for( j = i; j < N; j++ ) {
            if( A[j] < A[minj] ) {
                minj = j;
            }
        }
        swap(A[i],A[minj]);
        
        if( i != minj ) {
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    
    fstream file;
    string buf;
    int N = 0;
    int v = 0;
    int i, j, k;
    
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
    
    v = selectionSort(A,N);
    trace(A,N);
    cout << v << endl;
    
    delete[] A;
    
    file.close();
    
    return 0;
}
