#ifndef FibonacciAlgorithm_h
#define FibonacciAlgorithm_h

#include <vector>
using std::vector;

class FibonacciAlgorithm {
	//we could use an associative array BUT note that the indexes would be 0,1,2,3...which are array indexes
	//so it is more efficient to use a vector instead
    vector<int> memorizeTable;

public:

    FibonacciAlgorithm();

    int fibonacciMemorize(int n);
    int naiveFibonacci(int n);
};

#endif
