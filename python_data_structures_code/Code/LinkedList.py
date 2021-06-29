class Node:

    def __init__(self, data):
        self.data = data
        self.next_node = None


class LinkedList:

    def __init__(self):
        self.head = None
        self.num_of_nodes = 0

    # O(1)
    def insert_start(self, data):

        self.num_of_nodes = self.num_of_nodes + 1
        new_node = Node(data)

        # the head is NULL (so the data structure is empty)
        if not self.head:
            self.head = new_node
        # there is at lest one item in the linked list
        else:
            new_node.next_node = self.head
            self.head = new_node

    # O(N)
    def insert_end(self, data):

        self.num_of_nodes = self.num_of_nodes + 1
        new_node = Node(data)

        actual_node = self.head

        # we have to find the end of the linked list in O(N) linear running time
        while actual_node.next_node is not None:
            actual_node = actual_node.next_node

        # actual_node is the last node: so we insert the new_node right after the actual_node
        actual_node.next_node = new_node

    # O(1)
    def size_of_list(self):
        return self.num_of_nodes

    # have to consider all the items in O(N) linear running time
    def traverse(self):

        actual_node = self.head

        while actual_node is not None:
            print(actual_node.data)
            actual_node = actual_node.next_node

    # O(N) linear running time for finding arbitrary item
    def remove(self, data):

        # list is empty
        if self.head is None:
            return

        actual_node = self.head
        # we have to track the previous node for future pointer updates
        # this is why doubly linked lists are better - we can get the previous
        # node (here with linked lists it is impossible)
        previous_node = None

        # search for the item we want to remove (data)
        while actual_node is not None and actual_node.data != data:
            previous_node = actual_node
            actual_node = actual_node.next_node

        # search miss
        if actual_node is None:
            return

        # the head node is the one we want to remove
        if previous_node is None:
            self.head = actual_node.next_node
        else:
            # remove an internal node by updating the pointers
            # NO NEED TO del THE NODE BECAUSE THE GARBAGE COLLECTOR WILL DO THAT
            previous_node.next_node = actual_node.next_node


if __name__ == '__main__':

    linked_list = LinkedList()
    linked_list.insert_start(1)
    linked_list.insert_start(2)
    linked_list.insert_end(3)

    linked_list.remove(3)

    linked_list.traverse()
