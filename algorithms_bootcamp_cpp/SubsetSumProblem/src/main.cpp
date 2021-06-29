#include "SubsetSumProblem.h"

int main() {

	vector<int> numbers = { 5, 2, 3, 1, 20 };
	int sum = 21;

	SubsetSumProblem subsetSumProblem{ numbers, sum };
	subsetSumProblem.solveProblem();

	if (subsetSumProblem.hasSolution())
		subsetSumProblem.showSums();

	return 0;
}
