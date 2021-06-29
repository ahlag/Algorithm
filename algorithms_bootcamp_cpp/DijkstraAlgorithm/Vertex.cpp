#include "Vertex.h"
#include "Edge.h"
#include <cassert>


Vertex::Vertex(string const &name)
{
    this->name = name;
}

string Vertex::getName() const
{
    return name;
}

void Vertex::addNeighbour(Edge *edge)
{
    if (edge)
    {
        assert(edge->getStartVertex().get() == this);
        adjacenciesList.push_back(edge);
    }
}

const vector<Edge *> &Vertex::getAdjacenciesList()
{
    return adjacenciesList;
}

Vertex *Vertex::getPredecessor() const
{
    return predecessor;
}

void Vertex::setPredecessor(Vertex *predecessor)
{
    this->predecessor = predecessor;
}

double Vertex::getMinDistance() const
{
    return minDistance;
}

void Vertex::setMinDistance(double distance)
{
    minDistance = distance;
}

ostream &operator<<(ostream &strm, const Vertex& vert)
{
    strm << vert.name;
    return strm;
}
// v1 < v2 if v1.minDistance < v2.minDistance
bool Vertex::operator<(const Vertex &other) const
{
    return minDistance < other.minDistance;
}
