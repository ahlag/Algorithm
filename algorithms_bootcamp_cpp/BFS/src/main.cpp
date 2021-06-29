#include <iostream>
#include <memory.h>
#include "Vertex.h"
#include "BreadthFirstSearch.h"

using namespace std;

int main(int argc, const char * argv[]) {

	BreadthFirstSearch breadthFirstSearch;

    shared_ptr<Vertex> vertex1 = make_shared<Vertex>(1);
    shared_ptr<Vertex> vertex2 = make_shared<Vertex>(2);
    shared_ptr<Vertex> vertex3 = make_shared<Vertex>(3);
    shared_ptr<Vertex> vertex4 = make_shared<Vertex>(4);
    shared_ptr<Vertex> vertex5 = make_shared<Vertex>(5);

    vertex1->addNeighbour(vertex2.get());
    vertex1->addNeighbour(vertex4.get());
    vertex4->addNeighbour(vertex5.get());
    vertex2->addNeighbour(vertex3.get());

    breadthFirstSearch(vertex1);

    return 0;
}
