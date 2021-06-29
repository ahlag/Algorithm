#ifndef Heap_h
#define Heap_h

#include <vector>
using std::vector;

class Heap {

    //we represent the heap data structure with an array
    vector<int> heap;
    //we want to track the size (the number of items in the heap)
    int heapSize = 0;

    constexpr static int CAPACITY = 10;

public:
    Heap();

    //insertion takes O(1) running time BUT we have to make sure that the
    //heap properties are not violated (it takes O(logN) because of the fixUp() method)
    void insert(int item);

    //we return the root node. Because it is a max heap the root is the max item
    //of course because of the array representation it takes O(1) time
    //this is the peek() method
    int getMax() const;

    //it returns the maximum item + removes it from the heap
    //note: we just do not care about that item any more but because
    //we have an array with fix size we are not able to get rid of it completely
    //O(logN)
    int poll();

    //we have N items and we want to sort them with a heap
    //every poll() operation takes O(logN) time because of the fixDown() method thats why
    //the overall running time complexity is O(NlogN) for heapsort
    void heapsort();

private:
    //we consider the last item and checks whether swaps are needed or not
    //running time: O(logN)
    void fixUp(int index);

    //we have a given item in the heap and we consider all the item BELOW and check
    //whether the heap properties are violated or not
    void fixDown(int index);

    //checks whether the heap is full or not
    //note: we are not able to insert more items than the CAPACITY
    bool isHeapFull() const;
};

#endif /* Heap_h */
