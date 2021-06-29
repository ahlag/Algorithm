#include "KnapsackProblem.h"
#include <algorithm>
#include <iostream>

Knapsack::Knapsack(int _numOfItems, int _capacityOfKnapsack, const vector<int> &_weights, const vector<int> &_values)
    : numOfItems(_numOfItems)
    , capacityOfKnapsack(_capacityOfKnapsack)
    , weights(_weights)
    , values(_values)
{
	//table has as many rows as numOfItems+1 and as many columns as capacity+1
    knapsackTable.resize(numOfItems + 1);
    for (auto &item : knapsackTable)
        item.resize(capacityOfKnapsack + 1);
}

void Knapsack::operator()() {

	//we keep considering more and more items whether to include in the knapsack or not
    //time complexity: O(N*W)
    for(int i=1; i<numOfItems + 1; ++i) {
        for(int w = 1; w < capacityOfKnapsack + 1; ++w) {

        	//maximum value of the knapsack if we do NOT take item i
        	//S value
            int notTakingItem = knapsackTable[i-1][w];

            int takingItem = 0;

            //value of the knapsack if we take item i
            //of course we have to check whether it fits in the knapsack or not (weight constraint)
            if( weights[i] <= w ) {
                takingItem = values[i] + knapsackTable[i-1][w-weights[i]];
            }

            //we want to maximize our profit
            knapsackTable[i][w] = std::max(notTakingItem, takingItem);
        }
    }

    //maximum profit is the value of the last cell
    //because that is the case when we have as many items as the numOfItems and
    //as much capacity as capacityOfKnapsack
    totalBenefit = knapsackTable[numOfItems][capacityOfKnapsack];
}

void Knapsack::showResult() {

    std::cout << "Total benefit: " << totalBenefit << '\n';

    //we start with the last row and last column item
    for(int n=numOfItems, w = capacityOfKnapsack; n > 0; --n) {
    	//we take the item if it's value differ from the value in the row above
        if( knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n-1][w] ) {
            std::cout << "We take item: #" << n << '\n';
            //because we take that item we have less capacity
            w = w - weights[n];
        }
    }
}
