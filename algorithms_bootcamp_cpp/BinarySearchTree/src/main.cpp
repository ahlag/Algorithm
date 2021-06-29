#include <iostream>
#include "BinarySearchTree.h"
#include "Person.h"

int main() {

	std::shared_ptr<Tree<Person>> bst = std::make_shared<BinarySearchTree<Person>>();

    bst->insert(Person("Adam",27));
    bst->insert(Person("Kevin",13));
    bst->insert(Person("Joe",67));
    bst->insert(Person("Michael",2));
    bst->insert(Person("Smith",11));

    bst->traversal();

    return 0;
}
