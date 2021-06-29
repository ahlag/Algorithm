#include "Edge.h"

Edge::Edge(double _weight, const shared_ptr<Vertex> &_startVertex, const shared_ptr<Vertex> &_targetVertex)
    : weight(_weight)
    , startVertex(_startVertex)
    , targetVertex(_targetVertex)
{

}

double Edge::getWeight() const
{
    return weight;
}

shared_ptr<Vertex> Edge::getStartVertex() const
{
    return startVertex;
}

shared_ptr<Vertex> Edge::getTargetVertex() const
{
    return targetVertex;
}
