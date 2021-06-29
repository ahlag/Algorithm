#include <iostream>
#include <vector>
#include "KnapsackProblem.h"
using namespace std;

int main(int argc, const char * argv[]) {

	int numOfItems = 3;
    int capacityOfKnapsack = 5;

    vector<int> weightOfItems(4);
    weightOfItems[1] = 4;
    weightOfItems[2] = 2;
    weightOfItems[3] = 3;

    vector<int> profitOfItems(4);
    profitOfItems[1] = 10;
    profitOfItems[2] = 4;
    profitOfItems[3] = 7;

    Knapsack knapsack{numOfItems, capacityOfKnapsack, weightOfItems, profitOfItems};
    knapsack();
    knapsack.showResult();

    return 0;
}
