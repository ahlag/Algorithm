
class Node:

    def __init__(self, name):
        self.name = name
        self.adjacency_list = []
        self.visited = False


def depth_first_search(node):

    node.visited = True
    print(node.name)

    for n in node.adjacency_list:
        if not n.visited:
            depth_first_search(n)


if __name__ == '__main__':

    # first we have to create the vertices (nodes)
    node1 = Node("A")
    node2 = Node("B")
    node3 = Node("C")
    node4 = Node("D")
    node5 = Node("E")

    # handle and set the neighbors accordingly
    node1.adjacency_list.append(node2)
    node1.adjacency_list.append(node3)
    node2.adjacency_list.append(node4)
    node4.adjacency_list.append(node5)

    # run the DFS
    depth_first_search(node1)
