#include <iostream>

#include "Vertex.h"
#include "Edge.h"
#include "BellmanFord.h"

int main(int argc, const char * argv[]) {
    
    vector<Vertex> vertexList;
    
    vertexList.push_back(Vertex("A"));
    vertexList.push_back(Vertex("B"));
    vertexList.push_back(Vertex("C"));
    vertexList.push_back(Vertex("D"));
    vertexList.push_back(Vertex("E"));
    vertexList.push_back(Vertex("F"));
    vertexList.push_back(Vertex("G"));
    vertexList.push_back(Vertex("H"));
    
    vector<Edge> edgeList;
    edgeList.push_back(Edge(&vertexList[0], &vertexList[1], 5));
    edgeList.push_back(Edge(&vertexList[0], &vertexList[4], 9));
    edgeList.push_back(Edge(&vertexList[0], &vertexList[7], 8));
    edgeList.push_back(Edge(&vertexList[1], &vertexList[3], 12));
    edgeList.push_back(Edge(&vertexList[1], &vertexList[4], 15));
    edgeList.push_back(Edge(&vertexList[1], &vertexList[7], 4));
    edgeList.push_back(Edge(&vertexList[2], &vertexList[3], 3));
    edgeList.push_back(Edge(&vertexList[2], &vertexList[6], 11));
    edgeList.push_back(Edge(&vertexList[3], &vertexList[6], 9));
    edgeList.push_back(Edge(&vertexList[4], &vertexList[5], 4));
    edgeList.push_back(Edge(&vertexList[4], &vertexList[6], 20));
    edgeList.push_back(Edge(&vertexList[4], &vertexList[7], 5));
    edgeList.push_back(Edge(&vertexList[5], &vertexList[2], 1));
    edgeList.push_back(Edge(&vertexList[5], &vertexList[6], 13));
    edgeList.push_back(Edge(&vertexList[7], &vertexList[2], 7));
    edgeList.push_back(Edge(&vertexList[7], &vertexList[5], 6));
    
    BellmanFord bellmannFordAlgorithm = BellmanFord(vertexList,edgeList);
    bellmannFordAlgorithm(0, 6);
    
    return 0;
}
