#include "Heap.h"
#include <algorithm>
#include <iostream>
using std::cout;

Heap::Heap()
{
    heap.resize(CAPACITY);
}

void Heap::insert(int item) {

    //we are not able to insert more items than the value of the CAPACITY
    if(isHeapFull())
        throw std::overflow_error("Heap is full...");

    //insert the item + increment the counter
    heap[heapSize] = item;
    ++heapSize;

    //we insert the item to the last position of the array: of course the heap
    //properties may be violated so we have to fix it if necessary
    fixUp(heapSize-1);
}

//this is the peek operation for a max heap
int Heap::getMax() const {
    if (heapSize == 0)
        throw std::length_error("Heap is empty");

    return heap[0];
}

//poll operation: when we return the max item AND we get rid of it as well
int Heap::poll() {

    int max = getMax();

    std::swap(heap[0], heap[heapSize - 1]);
    --heapSize;

    fixDown(0);
    return max;
}

//natural order of items in the heap (sort integers)
void Heap::heapsort() {

    //we decrease the size of the heap in the poll() method so we have to store it (!!!)
    int size = heapSize;

    //we call the poll operation as many times as the number of items in the heap
    for(int i=0;i<size;++i) {
        int max = poll();
        cout << max << ' ';
    }

    cout << '\n';
}

void Heap::fixUp(int index) {

    //the parent index of the given node in the heap
    //we store the heap in an array (!!!)
    int parentIndex = (index-1)/2;

    //while the index>0 means until we consider all the items "above" the one we inserted
    //we have to swap the node with the parent if the heap property is violated
    //it is a MAX HEAP: largest items are in the higher layers (max item == root node)
    if(index > 0 && heap[index] > heap[parentIndex]) {
        std::swap(heap[index], heap[parentIndex]);
        fixUp(parentIndex);
    }
}

void Heap::fixDown(int index) {

    //every node have  children: left child and right child
    //in the array the node i has left child with index *i+1 and right child with index 2*i+1
    int indexLeft = 2*index+1;
    int indexRight = 2*index+2;
    //max heap so the parent node is always greater than the children
    int indexLargest = index;

    //if the left child is greater than the parent: largest is the left node
    if(indexLeft < heapSize && heap[indexLeft] > heap[index])
        indexLargest = indexLeft;

    //if the right child is greater than the left child: largest is the right node
    if(indexRight < heapSize && heap[indexRight] > heap[indexLargest])
        indexLargest = indexRight;

    //we do not want to swap items with themselves
    if(index!=indexLargest) {
        std::swap(heap[index], heap[indexLargest]);
        fixDown(indexLargest);
    }
}

bool Heap::isHeapFull() const {
    return CAPACITY == heapSize;
}
