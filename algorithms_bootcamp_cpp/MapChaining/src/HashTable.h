#ifndef HashTable_hpp
#define HashTable_hpp

#include <vector>
#include <list>
using std::vector;
using std::list;

class HashTable {

	//the maximum item we can store in the map
    static constexpr int TABLE_SIZE = 10;

    //every item we insert is a (key,value) pair
    struct HashItem {
        int key = 0;
        int value = 0;
    };

    //a single array index may store more item: we store these items in a list
    vector<list<HashItem>> hashTable;

public:

    HashTable();

    //O(1) if the hash function is perfect
    int get(int key);
    //O(1) if the hash function is perfect
    void put(int key, int value);

private:
    static int hash(int key);
};

#endif
