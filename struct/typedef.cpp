#include <iostream>

#define N 2

typedef double Matrix[N][N]; //Definition of Matrix
typedef double Vector[N]; //Definition of Vector

using namespace std;

int main() {
    Matrix a;
    Vector b;
    int i,j;
    
    cout << N << "次正方行列Aの各要素を入力してもらいます。" << endl;
    
    for( i = 0; i < N ; i++ ) {
        cout << "第" << i+1 << "行の要素を入力してください";
        for( j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << N << "次元ベクトルbの各要素を入力してもらいます。" << endl;
    for( i = 0; i < N; i++ ) {
        cin >> b[i];
    }
    
    cout << "入力した行列は次の通りです。" << endl;
    for( i = 0; i < N; i++ ) {
        for( j = 0; j < N; j++ ) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    
    cout << "入力したベクトルは次の通りです。" << endl;
    for( i = 0; i < N; i++ ) cout << b[i] << endl;
    
    return 0;
}
