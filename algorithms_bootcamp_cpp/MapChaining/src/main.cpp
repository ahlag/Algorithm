#include "HashTable.h"
#include <iostream>

int main() {

	HashTable hashTable {};

    hashTable.put(1,1);
    hashTable.put(11,10);
    hashTable.put(21,100);


    std::cout << hashTable.get(1) << ' ';
    std::cout << hashTable.get(11) << ' ';
    std::cout << hashTable.get(21) << ' ';

    return 0;
}
