#include "DijkstraAlgorithm.h"
#include <set>
#include <iostream>


void DijkstraAlgorithm::computePaths(shared_ptr<Vertex> sourceVertex)
{
    auto fCompare = [&](shared_ptr<Vertex> const &l, shared_ptr<Vertex> const &r)
    {
        return *l < *r;
    };

    sourceVertex->setMinDistance(0.);
    // queue data structure
    std::multiset<shared_ptr<Vertex>, decltype(fCompare)> queue(fCompare);
    // insert the starting vertex
    queue.insert(sourceVertex);

    while (!queue.empty())
    {
        auto iBegin = queue.begin();
        auto actualVertex = *iBegin;
        queue.erase(iBegin);

        for (const Edge *edge : actualVertex->getAdjacenciesList())
        {
            shared_ptr<Vertex> from = edge->getStartVertex();
            shared_ptr<Vertex> to = edge->getTargetVertex();

            double newDistance = actualVertex->getMinDistance() + edge->getWeight();
            
            if (newDistance < to->getMinDistance()) {

                // Fibonacci heaps can do it in O(1) BUT here we have to
                // look for the item to be removed in O(V)
                for (auto it = queue.begin(); it != queue.end(); ++it)
                {
                    if ((*it)->getName() == to->getName())
                    {
                        queue.erase(it);
                        break;
                    }
                }
                
                // update and insert the vertex to the heap (multiset)
                to->setMinDistance(newDistance);
                to->setPredecessor(actualVertex.get());
                queue.insert(to);
            }
        }
    }
}

vector<Vertex *> DijkstraAlgorithm::getShortestPath(shared_ptr<Vertex> vertex) const
{
    std::cout << "Min distance: " << vertex->getMinDistance() << std::endl;
    
    vector<Vertex *> path;
    for (Vertex *it = vertex.get(); it != nullptr; it = it->getPredecessor())
        path.push_back(it);

    std::reverse(path.begin(), path.end());
    return path;
}
