#ifndef Edge_h
#define Edge_h

class Vertex;

class Edge {
    
    int weight;
    Vertex *startVertex;
    Vertex *targetVertex;

public:
    Edge(Vertex *startVertex, Vertex *targetVertex, int weight);
    
    int getWeight() const;
    
    void setWeight(int weight);
    
    Vertex *getStartVertex() const;
    
    void setStartVertex(Vertex *startVertex);
    
    Vertex *getTargetVertex() const;
    
    void setTargetVertex(Vertex *targetVertex);
};

#endif 
