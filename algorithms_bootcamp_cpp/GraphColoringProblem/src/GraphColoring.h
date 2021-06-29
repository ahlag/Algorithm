#ifndef GraphColoring_h
#define GraphColoring_h

#include <vector>
using std::vector;

class GraphColoring {
	vector<vector<int>> graphMatrix;
    int numOfColors;
    vector<int> colors;

public:
    GraphColoring(const vector<vector<int>> &graph, int _numOfColors);

    //solve the coloring problem
    void operator()();

private:
    //function to assign colors recursively
    bool solve(size_t nodeIndex);

    //function to check if it is valid to allot that color to vertex
    bool isColorValid(size_t nodeInex, size_t colorIndex);

    void showResult();
};

#endif /* GraphColoring_h */
