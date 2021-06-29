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

int bubbleSort( int A[], int N ) {
    
    int sw = 0;
    bool flag = 1;
    
    for( int i = 0; flag; i++ ) {
        flag = 0;
        for ( int j = N-1 ; j > i ; j-- ) {
            if( A[j] < A[j-1] ) {
                swap(A[j],A[j-1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    
    fstream file;
    string buf;
    int N = 0;
    int v = 0;
    int sw;
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
    
    sw = bubbleSort(A,N);

    for( int i = 0; i < N; i++ ) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    
    delete[] A;
    
    file.close();
    
    return 0;
}
