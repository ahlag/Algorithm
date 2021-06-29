import time


class Node:

    def __init__(self, data):
        self.data = data
        self.next_node = None


class LinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    def insert(self, data):

        self.size = self.size + 1
        new_node = Node(data)

        if not self.head:
            self.head = new_node
        else:
            new_node.next_node = self.head
            self.head = new_node


if __name__ == '__main__':

    linked_list = LinkedList()

    now = time.time()

    for i in range(500000):
        linked_list.insert(i)

    print('Inserting items into Linked List in %ss' % str(time.time()-now))

    array = []
    now = time.time()

    for i in range(500000):
        array.insert(0, i)

    print('Inserting items into Array in %ss' % str(time.time() - now))
