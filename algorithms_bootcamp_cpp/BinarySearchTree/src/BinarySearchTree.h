#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"
#include <memory>
#include <iostream>
#include <exception>

//we can create our custom exception (when the tree is empty)
class EmptyTreeException : std::exception {
public:
    EmptyTreeException() {};

    const char *what() const noexcept override
    {
        return "BinarySearchTree is empty()";
    }

};

template<typename t_Data>
class BinarySearchTree : public Tree<t_Data>
{
	//every tree contains several nodes
	//every nodes have a left child and right child and the data of course
    struct Node
    {
        t_Data data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const t_Data &_data)
            : data(_data)
        {}
    };

    //as usual we can access the root node exclusively (and access all other nodes via the root node)
    std::unique_ptr<Node> root;

public:

    //inserting nodes into the tree in O(logN) complexity
    void insert(const t_Data &data) override {
        if (root) {
        	//not the first node
            insertNode(data, root.get());
        } else {
        	//inserting the first node
            root = std::make_unique<Node>(data);
        }
    }

    //we can visit all the nodes of the tree in O(N)
    void traversal() const override {

    	//if the root does not exist we return
        if (!root)
            return;

        inOrderTraversal(root.get());
        std::cout << '\n';
    }

    //remove operation in O(logN)
    void remove(const t_Data &data) override {

    	//if the root does not exist (no nodes in the tree) we return
    	if (!root)
            return;

        remove(data, root);
    }

    const t_Data &getMaxValue() const override {

    	if (!root)
            throw EmptyTreeException{};

        return getMax(root.get());
    }

    const t_Data &getMinValue() const override {

    	if (!root)
            throw EmptyTreeException{};

        return getMin(root.get());
    }

private:

    //insert new node into the tree in O(logN) running time
    void insertNode(const t_Data &data, Node *node) {

    	//if the data is smaller: we go to the left
    	if (data < node->data) {
    		//let's find the location recursively where to insert
            if (node->left)
                insertNode(data, node->left.get());
            else
            	//no left node: this is the location where we have to insert
                node->left = std::make_unique<Node>(data);
        } else {
        	//else we have to go to the right subtree and find the location
            if (node->right)
                insertNode(data, node->right.get());
            else
            	//no right node: so this is where to insert
                node->right = std::make_unique<Node>(data);
        }
    }

    //in-order traversal: visit left subtree then root then right subtree
    void inOrderTraversal(Node *node) const {

        if (node->left)
            inOrderTraversal(node->left.get());

        std::cout << node->data << "  -->  ";

        if (node->right)
            inOrderTraversal(node->right.get());
    }

    void remove(const t_Data &data, std::unique_ptr<Node> &nodeRef) {

    	//first we have to find the node we want to remove
        if(data < nodeRef->data) {
            if (nodeRef->left)
                remove(data, nodeRef->left);
        } else if (data > nodeRef->data) {
            if (nodeRef->right)
                remove(data, nodeRef->right);
        } else {

            // we have found the node we want to remove !!!
        	//removing a leaf node
            if(!nodeRef->left && !nodeRef->right) {
                std::cout << "Removing a leaf node...\n";
                nodeRef.reset();
                return;
            }

            //removing a right child
            if(!nodeRef->left) {
                std::cout << "Removing the right child...\n";
                std::unique_ptr<Node> temp = std::move(nodeRef->right);
                nodeRef.reset();
                nodeRef = std::move(temp);
                return;
            //removing a left child
            } else if(!nodeRef->right) {
                std::cout << "Removing the left child...\n";
                std::unique_ptr<Node> temp = std::move(nodeRef->left);
                nodeRef.reset();
                nodeRef = std::move(temp);
                return;
            }

            // we remove a node with two children case !!!
            std::cout << "Removing item with two children...\n";
            //we find the largest item in the left subtree (or the smallest in the right subtree is valid as well)
            //this is the PREDECESSOR
            std::unique_ptr<Node> temp = detachRightMost(nodeRef->left);

            temp->right = std::move(nodeRef->right);
            std::unique_ptr<Node> &tempLeftMost = getLeftMost(temp);
            tempLeftMost->left = std::move(nodeRef->left);
            //destroys the object currently managed by the unique_ptr
            nodeRef.reset();
            nodeRef = std::move(temp);
        }
    }

    //get the previous node in the in-order traversal order (so the largest node in the left subtree)
    std::unique_ptr<Node> detachRightMost(std::unique_ptr<Node> &nodeRef) {
        if (nodeRef->right)
            return detachRightMost(nodeRef->right);

        return std::move(nodeRef);
    }

    std::unique_ptr<Node> &getLeftMost(std::unique_ptr<Node> &nodeRef)
    {
        if (nodeRef->left)
            return getLeftMost(nodeRef->left);

        return nodeRef;
    }

    //get largest item in the tree in O(logN)
    const t_Data &getMax(Node *node) const {

    	//we are after the rightmost node
        if (node->right) {
            return getMax(node->right.get());
        }

        return node->data;
    }

    //get smallest item in the tree in O(logN)
    const t_Data &getMin(Node *node) const {

    	//we are after the leftmost node
        if (node->left) {
            return getMin(node->left.get());
        }

        return node->data;
    }

};
#endif
