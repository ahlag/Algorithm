#ifndef Vertex_h
#define Vertex_h

#include <vector>
#include <ostream>
using namespace std;

//these are the nodes in the graph
class Vertex {

private:
	//nodes in the graph has a data
    int data = 0;
    //boolean flag to know whether we have already visited the given node
    bool visited = false;
    //adjacency list: neighbors of the given node
    vector<Vertex *> neighbours;

public:
    Vertex(int data);
	~Vertex();

    int getData() const;
    void setData(int data);

    bool isVisited() const;
    void setVisited(bool visited);

    const vector<Vertex *> &getNeighbourList() const;
    void addNeighbour(Vertex *neighbour);

    friend ostream &operator<<(ostream &os, const Vertex &vertex);
};

#endif
