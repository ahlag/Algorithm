#include <iostream>

using namespace std;

void tail(int n) {

	if(n==0) return;

	//we do a certain operation
	cout << "Tail function called with n=" << n << endl;

	//and then call the function recursively: the stack will not store the previous calls
	tail(n-1);
}

void head(int n) {

	if(n==0) return;

	//we call the function recursively
	head(n-1);

	//and then we do the operation: so the stack has to store the previous states (function calls)
	cout << "Head function called with n=" << n << endl;
}

int main() {

	head(5);

	return 0;
}
