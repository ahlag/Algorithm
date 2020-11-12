#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int a[] = {1,2,3,4,5,10};
	int *p1, *p2;
	
	p1 = a;
	p2 = &a[1];
	
	cout << "*p1 = " << *p1 << " p1 = " << p1 << endl;
	cout << "*p2 = " << *p2 << " p2 = " << p2 << endl;
    
    cout << endl;
    cout << "array pointing" << endl;
    cout << endl;
    
    int N = sizeof(a)/sizeof(a[0]);
    
    for( int i = 0; i < N; i++) {
        cout << "a[ " << i << " ] = " << " *p =" << *(p1+i) << endl;
    }

	return 0;
}
