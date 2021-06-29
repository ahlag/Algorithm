#pragma once

#include "List.h"
#include <memory>
#include <iostream>

//we use templates so a bit more complicated (we should use header files and not .cpp files)

template<class t_Data>
class LinkedList : public List<t_Data>
{
	//linked list consist of nodes: nodes have data and pointer to the next node
	struct Node
	{
		t_Data data;
		//reference to the next node (unique_ptr frees memory automatically!!!)
		std::unique_ptr<Node> nextNode;

		Node(const t_Data &_data)
			: data(_data)
		{}
	};

	//we track the size of the list (so the number of nodes so far)
	int sizeCounter = 0;
	//we store a reference to the head node (quite common when dealing with data structures)
	std::unique_ptr<Node> head;

public:

	LinkedList() = default;

	//insert data to the front
	void insert(const t_Data &data) override
	{
		++sizeCounter;
		insertDataBeginning(data);
	}

	//remove node from the front
	void remove(const t_Data &data) override
	{
		//if the list is empty we return
		if (!head)
			return;

		//if it is the head we want to remove (O(1))
		if (head->data == data) {
			auto newhead = std::move(head->nextNode);
			head = std::move(newhead);
			--sizeCounter;
			return;
		}

		if (!head->nextNode) {
			std::cout << data << " is not found in a list";
			return;
		}

		//it is an internal node we want to remove (so a bit more complex)
		//initialize the helper nodes (we need them for updating references)
		//again we accessing pointers that are under unique_ptr memory management so no need to free
		Node *prev = head.get();
		Node *next = head->nextNode.get();

		//first we have to find the node we want to get rid of
		while (next->data != data) {
			prev = next;
			next = next->nextNode.get();
		}

		//we considered all the nodes without any result so the node is not present in the list
		if (!next) {
			std::cout << data << " is not found in a list";
			return;
		}

		//we have to update the references
		std::unique_ptr<Node> temp = std::move(next->nextNode);
		prev->nextNode = std::move(temp);
	}

	void traverseList() const override {

		//start with the head
		Node *node = head.get();

		//while the node is not a NULL we print out the data
		while (node) {
			std::cout << node->data << ' ';
			node = node->nextNode.get();
		}

		std::cout << '\n';
	}

	//we can get the number of nodes (size) in O(1) running time
	int size() const override {
		return sizeCounter;
	}

private:

	void insertDataBeginning(const t_Data &data)
	{
		//we just have to update the references
		//this operation is quite fast O(1) running time
		std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
		newNode->nextNode = std::move(head);
		head = std::move(newNode);
	}
};
