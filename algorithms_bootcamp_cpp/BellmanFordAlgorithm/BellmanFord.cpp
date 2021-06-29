#include "BellmanFord.h"
#include <iostream>

void BellmanFord::operator()(size_t sourceVertexIndex, size_t targetVertexIndex) const {
    
    if (sourceVertexIndex >= vertexList.size() || targetVertexIndex >= vertexList.size())
        return;
    
    Vertex& sourceVertex = vertexList[sourceVertexIndex];
    Vertex& targetVertex = vertexList[targetVertexIndex];
    
    sourceVertex.setMinDistance(0);
    
    // we have to make V-1 iterations
    for (int i=0;i<vertexList.size()-1;i++) {
        // we have to consider all the edges (relaxation)
        for (auto const &edge : edgeList) {
            
            int newDistance = edge.getStartVertex()->getMinDistance() + edge.getWeight();
            
            if (newDistance < edge.getTargetVertex()->getMinDistance()) {
                // update the min distance
                edge.getTargetVertex()->setMinDistance(newDistance);
                // update the predecessor to track the shortest path
                edge.getTargetVertex()->setPreviousVertex(edge.getStartVertex());
            }
        }
    }
    
    // additional iteration to check negative cycles
    for (Edge edge : edgeList) {
        if (edge.getStartVertex()->getMinDistance() != MAX_VALUE) {
            if ( hasCycle(edge) ) {
                cout << "Negative edge weight cycles detected!\n";
                return;
            }
        }
    }
    
    if (targetVertex.getMinDistance() != MAX_VALUE) {
        cout << "There is a shortest path from source to target, with cost: " << targetVertex.getMinDistance() << '\n';
        
        Vertex *actualVertex = &targetVertex;
        while( actualVertex != nullptr ){
            cout << *actualVertex << '-';
            actualVertex = actualVertex->getPreviousVertex();
        }
        
        cout << '\n';
        
    } else {
        cout << "There is no path from source to target...\n";
    }
}

bool BellmanFord::hasCycle(Edge const &edge) const {
    return edge.getTargetVertex()->getMinDistance() > edge.getStartVertex()->getMinDistance() + edge.getWeight();
}
