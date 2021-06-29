#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

//we can implement queue abstract data type with linked list as an underlying data structure
template<class t_Data>
class Queue
{
	//linked list data structure has nodes
	struct Node
	{
		t_Data data;
		unique_ptr<Node> nextNode;

		Node(const t_Data &_data)
			:data(_data)
		{}
	};

	//if we want to make sure that enqueue/dequeue operations will have O(1) running time
	//we have to store a reference to the head (first node) and to the tail (last node)
	unique_ptr<Node> firstNode; // head node
	Node *lastNode = nullptr; //tail node
	int count = 0;

public:

	//checking whether the queue is empty or not [O(1)]
	bool isEmpty() const {
		return firstNode == nullptr;
	}

	//we count the number of nodes so thats why this operation has O(1) running time
	int size() const {
		return count;
	}

	//adding item to the queue in O(1)
	//we keep inserting new items to the end of the queue
	void enqueue(const t_Data &newData) {

		++count;

		Node *oldLastNode = lastNode;
		auto newLastNode = make_unique<Node>(newData);
		lastNode = newLastNode.get();

		//for the first node: it is the first as well as the last node
		if (isEmpty()) {
			firstNode = std::move(newLastNode);
		} else {
			//updating the reference
			oldLastNode->nextNode = std::move(newLastNode);
		}
	}

	//removing item in O(1)
	//we keep removing items from the beginning of the queue
	t_Data dequeue() {

		//if the queue is empty then we return
		if (isEmpty())
			throw std::out_of_range("Queue is empty.");

		--count;

		//remove the first item and update the references
		t_Data dataToDequeue = std::move(firstNode->data);
		unique_ptr <Node> temp = std::move(firstNode->nextNode);
		firstNode = std::move(temp);

		//if we call dequeue when there is just 1 item in the queue
		if (isEmpty()) {
			lastNode = nullptr;
		}

		return dataToDequeue;
	}
};
