#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

template<class t_Data>
class Stack
{
	//we use a linked list as an underlying data structure
	struct Node
	{
		t_Data data;
		unique_ptr<Node> nextNode;

		Node (const t_Data &_data)
			: data(_data)
		{}
	};

	//we have access to the head node (first node)
	unique_ptr<Node> head;
	int count = 0;

public:

	//because inserting items into a linked list takes O(1) thats why this operation is O(1)
	void push(const t_Data &newData) {

		//this is the first node we insert
		if (!head) {
			head = make_unique<Node>(newData);
		} else {
			//update the references
			unique_ptr<Node> oldhead = std::move(head);
			head = make_unique<Node>(newData);
			head->nextNode = std::move(oldhead);
		}

		++count;
	}

	//removing item from a linked list takes O(1) thats why this operation is O(1)
	t_Data pop() {

		if (isEmpty())
			throw std::out_of_range("Stack is empty.");

		//we have to remove the head node and update the references
		t_Data itemToPop = head->data;
		unique_ptr<Node> temp = std::move(head->nextNode);
		head = std::move(temp);

		--count;

		return itemToPop;
	}

	//O(1) operation
	bool isEmpty() const {
		return !head;
	}

	//O(1) operation
	int size() const {
		return count;
	}
};
