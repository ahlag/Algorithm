#pragma once
#include <string>
#include <memory>
#include <ostream>
#include <vector>
#include <numeric>
using std::string;
using std::shared_ptr;
using std::ostream;
using std::vector;

class Node;
class Edge;

const int MAX_VALUE = 10e7;

class Vertex
{
    string name;
    vector<Edge *> adjacenciesList;
    Vertex *predecessor = nullptr;
    double minDistance = MAX_VALUE;

public:
    Vertex(string const &name);

    string getName() const;
    
    void addNeighbour(Edge *edge);
    const vector<Edge *> &getAdjacenciesList();

    Vertex *getPredecessor() const;
    void setPredecessor(Vertex *predecessor);

    double getMinDistance() const;
    void setMinDistance(double distance);

    friend ostream &operator<<(ostream &strm, const Vertex& vert);
    
    // we will compare objects of Vertexes
    // how to know which one is smaller and greater?
    bool operator<(const Vertex &other) const;
};

