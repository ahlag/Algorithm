#pragma once
#include "Vertex.h"
#include "Edge.h"

class DijkstraAlgorithm
{
public:
    void computePaths(shared_ptr<Vertex> sourceVertex);
    vector<Vertex *> getShortestPath(shared_ptr<Vertex> vertex) const;
};
