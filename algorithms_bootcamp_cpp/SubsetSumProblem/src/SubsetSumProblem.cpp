#include "SubsetSumProblem.h"
#include <iostream>

SubsetSumProblem::SubsetSumProblem(const vector<int> &_numbers, int _sum)
	: numbers(_numbers)
	, sum (_sum)
{
	dpTable.resize(numbers.size() + 1);
	for (auto &dpRow : dpTable)
		dpRow.resize(sum + 1);
}

void SubsetSumProblem::solveProblem()
{
	// if sum is 0 the we can make the empty subset to make sum 0
	for (size_t i = 0; i <= numbers.size(); i++) {
		dpTable[i][0] = true;
	}

	for (size_t rowIndex = 1; rowIndex <= numbers.size(); ++rowIndex) {
		for (int currentSum = 1; currentSum <= sum; ++currentSum) {

			if (currentSum < numbers[rowIndex - 1]) {
				dpTable[rowIndex][currentSum] = dpTable[rowIndex - 1][currentSum];
			}
			else {
				if (dpTable[rowIndex - 1][currentSum]) {
					dpTable[rowIndex][currentSum] = true;
				}
				else {
					dpTable[rowIndex][currentSum] = dpTable[rowIndex - 1][currentSum - numbers[rowIndex - 1]];
				}
			}
		}
	}
}

bool SubsetSumProblem::hasSolution()
{
	for (size_t i = 0; i < numbers.size() + 1; ++i) {
		for (int j = 0; j < sum + 1; ++j) {
			std::cout << (bool)dpTable[i][j] << ' ';
		}

		std::cout << '\n';
	}

	if (dpTable[numbers.size()][sum]) {
		std::cout << "There is a solution for the problem..." << '\n';
		return true;
	} else {
		std::cout <<  "No feasible solution for the problem..." << '\n';
		return false;
	}
}

void SubsetSumProblem::showSums()
{
	int currentSum = sum;
	int rowIndex = numbers.size();

	while (currentSum > 0 || rowIndex > 0) {

		if (dpTable[rowIndex][currentSum] == dpTable[rowIndex - 1][currentSum]) {
			rowIndex = rowIndex - 1;
		}
		else {
			std::cout << "We take item: " << numbers[rowIndex - 1] << '\n';
			currentSum = currentSum - numbers[rowIndex - 1];
			rowIndex = rowIndex - 1;
		}
	}
}
