#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    
    fstream file;
    string buf;
    int N = 0;
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
    
    int flag = 1;
    
    for( i = 0; flag; i++ ) {
        flag = 0;
        for( j = N - 1; j >= i + 1 ; j -- ) {
            if( A[j] < A[j-1] ) {
                swap(A[j],A[j-1]);
                flag = 1;
                
                cnt++;
                cout << "cnt = " << cnt << endl;
            }
        }
        
        for( k = 0; k < N; k++ ) {
            cout << A[k] << " ";
        }
        cout << endl;
    
/*
    while( flag != 0 ) {
        flag = 0;
        for( j = N - 1; j >= 0; j -- ) {
            if( A[j] < A[j-1] ) {
                v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
                flag = 1;
                
                cnt++;
            }
        }
        
        for( k = 0; k < N; k++ ) {
            cout << A[k] << " ";
        }
        cout << endl;
*/
//        cnt++;
    }
    
    for( k = 0; k < N; k++ ) {
        cout << A[k] << " ";
    }
    cout << endl;
    cout << cnt << endl;

/*
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
 */
    
    delete[] A;
    
    file.close();
    
    return 0;
}
