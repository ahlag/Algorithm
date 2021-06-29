#include <iostream>
#include <vector>
#include "GraphColoring.h"
using std::vector;

int main(int argc, const char * argv[]) {

	const vector<vector<int>> graphMatrix = {
        {0,1,0,1,0},
        {1,0,1,1,0},
        {0,1,0,1,0},
        {1,1,1,0,1},
        {0,0,0,1,0}
    };

    constexpr int numOfColors = 2;

    GraphColoring graphColoring(graphMatrix, numOfColors);
    graphColoring();

    return 0;
}
