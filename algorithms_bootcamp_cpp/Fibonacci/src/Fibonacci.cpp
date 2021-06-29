#include <iostream>

using namespace std;

int fibonacci(int n) {

	//recursive function so we have to define the base cases
	if(n==0) return 0;
	if(n==1) return 1;

	//this is the formula for Fibonacci numbers

	int fib1 = fibonacci(n-1);
	int fib2 = fibonacci(n-2);

	return fib1+fib2;
}

int main() {

	cout << fibonacci(10) << endl;

	return 0;
}
