#include "FibonacciProblem.h"
#include <iostream>
using std::cout;

int main() {

    FibonacciAlgorithm fibonacciAlgorithm;

    //cout << fibonacciAlgorithm.fibonacciMemorize(60) << '\n';
    cout << fibonacciAlgorithm.naiveFibonacci(60) << '\n';

    return 0;
}
