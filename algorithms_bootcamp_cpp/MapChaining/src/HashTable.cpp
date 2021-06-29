#include "HashTable.h"
#include <iostream>
using std::cout;

HashTable::HashTable() {
    hashTable.resize(TABLE_SIZE);
}

//we want to get a given value associated with a given key
int HashTable::get(int key) {

	//the hash function transforms the key -> into an array index
    int generatedArrayIndex = hash(key);

    //maybe there are already items with this index (the list stores these items)
    list<HashItem> &items = hashTable[generatedArrayIndex];

    //the value does not exist so we return
    if( hashTable[generatedArrayIndex].empty())
        return -1;

    //let's search for the item [O(N) linear running time complexity]
    //BOTTLENECK: this is why the data structure's running time may be reduced to O(N) if all the
    //items are hashed into the same array slot (so same index)
    for (HashItem const &item : items) {
        if (item.key == key)
            return item.value;
    }

    //search miss
    return -1;
}

//we want to insert a given value with a given key
void HashTable::put(int key, int value) {

	//the hash function transforms the key -> into an array index
    int hashArrayIndex = hash(key);

    //maybe there are already items with this index (the list stores these items)
    list<HashItem> &items = hashTable[hashArrayIndex];

    //if the vector is empty: it means that this is the first item with this index
    if( items.empty() ) {
        cout << "No collision simple insertion...\n";
    } else {

    	//the list is not empty: there are already items with this key (collision)
        cout << "Collision when inserting with key " << key << '\n';

        //if the key is already present in the map we could update (now we just return)
        for (HashItem const &item : items) {

            if (item.key == key) {
                cout << "item is already inserted...\n";
                return;
            }
        }
    }

    //insert the new item to this array index
    items.push_back(HashItem{key, value});

    cout << "Size of the list is " << items.size() << '\n';
}

//we use a very simple hash function
//we should use a more complicated one with prime numbers to
//avoid clustering etc.
int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}
