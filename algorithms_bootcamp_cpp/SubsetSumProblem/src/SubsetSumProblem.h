#pragma once
#include <vector>
using std::vector;

class SubsetSumProblem {
	vector<int> numbers;
	int sum = 0;
	vector<vector<bool>> dpTable;

public:
	SubsetSumProblem(const vector<int> &numbers, int sum);

	void solveProblem();
	bool hasSolution();
	void showSums();
};
