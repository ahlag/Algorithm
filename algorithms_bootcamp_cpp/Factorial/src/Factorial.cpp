#include <iostream>

using namespace std;

int factorial(int n) {

	//we have to define a base case
	if(n==1) return 1;

	//we keep reducing the problem -> thats why we have to store these states on the stack
	return n*factorial(n-1);
}

//we have the accumulator as well that tracks the result so far
int factorialAccumulator(int n,int accumulator) {

	//we have to define a base case: return the accumulator which is the solution
	if(n==1) return accumulator;

	//tail recursion BUT no need to store the state on the stack !!!
	//all the variables are known: n and accumulator
	return factorialAccumulator(n-1,n*accumulator);
}

int main() {

	//accumulator's value is 1 at the beginning
	cout << factorialAccumulator(5,1) << endl;

	return 0;
}
