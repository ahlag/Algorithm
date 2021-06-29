#include "Vertex.h"
#include <iostream>

Vertex::Vertex(int data) {
    this->data = data;
}

Vertex::~Vertex()
{
}

int Vertex::getData() const
{
    return data;
}

void Vertex::setData(int data)
{
    this->data = data;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

const vector<Vertex *> &Vertex::getNeighbourList() const {
    return neighbours;
}

void Vertex::addNeighbour(Vertex *neighbour)
{
    neighbours.push_back(neighbour);
}

// to String
ostream &operator<<(ostream& strm, const Vertex &vertex)
{
    strm << vertex.data;
    return strm;
}
