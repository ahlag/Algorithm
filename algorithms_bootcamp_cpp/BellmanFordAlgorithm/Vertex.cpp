#include "Vertex.h"

Vertex::Vertex(string id) {
    this->id = id;
}

int Vertex::getMinDistance() const {
    return minDistance;
}

void Vertex::setMinDistance(int minDistance) {
    this->minDistance = minDistance;
}

Vertex *Vertex::getPreviousVertex() const {
    return previousVertex;
}

void Vertex::setPreviousVertex(Vertex *previousVertex) {
    this->previousVertex = previousVertex;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

ostream &operator<<(ostream& strm, const Vertex &vertex)
{
    strm << vertex.id;
    return strm;
}
