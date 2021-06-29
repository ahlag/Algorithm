#ifndef Vertex_h
#define Vertex_h

#include "Edge.h"
#include <vector>
#include <limits>
#include <ostream>
using namespace std;

const int MAX_VALUE = 10e7;

class Vertex {

private:
    
    string id;
    bool visited;
    int minDistance = MAX_VALUE;
    Vertex *previousVertex = nullptr;
    
public:
    Vertex(string id);
    
    int getMinDistance() const;
    
    void setMinDistance(int minDistance);
    
    Vertex *getPreviousVertex() const;
        
    void setPreviousVertex(Vertex *previousVertex);
    
    bool isVisited() const;
    
    void setVisited(bool visited);
    
    friend ostream &operator<<(ostream &os, const Vertex &vertex);
};

#endif
