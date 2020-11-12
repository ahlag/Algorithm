#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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
    
    for( i = 1; i < N; i++ ) {
        
        v = A[i];
        j = i - 1;
        
        while( j >= 0 && A[j] > v ) {
            A[j+1] = A[j];
            j--;
//            A[j+1] = v;
        }
        A[j+1] = v;
        
        for( k = 0; k < N; k++ ) {
            cout << A[k] << " ";
        }
        cout << endl;
    }
    
    
    delete[] A;
    
    file.close();
    
    return 0;
}
