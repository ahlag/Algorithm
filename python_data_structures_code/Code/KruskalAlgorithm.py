
class Vertex:

    # this is the node or the vertex in the G(V,E)
    def __init__(self, name):
        self.name = name
        # is the node representation (disjoint sets)
        self.node = None


class Edge:

    def __init__(self, weight, start_vertex, target_vertex):
        self.weight = weight
        self.start_vertex = start_vertex
        self.target_vertex = target_vertex

    # Kruskal's algorithm sorts the edges by the weights
    # Python must know how to compare edges
    # we will sort the edges based on the weights
    def __lt__(self, other_edge):
        return self.weight < other_edge.weight


class Node:

    # node in the tree representation of the disjoint sets
    def __init__(self, rank, node_id, parent=None):
        self.rank = rank
        self.node_id = node_id
        self.parent = parent


class DisjointSet:

    def __init__(self, vertex_list):
        self.vertex_list = vertex_list
        # these are the root nodes (representatives) of the disjoint sets
        self.root_nodes = []
        # let's create as many disjoint sets as the number of vertices in the G(V,E)
        self.make_sets()

    # the aim of the find() function is to find the root node which is the representative
    # of that given disjoint set
    def find(self, node):

        # first we have to find the root node (representative)
        current_node = node

        while current_node.parent is not None:
            current_node = current_node.parent

        # apply "path compression"
        root = current_node
        current_node = node

        # we have to make sure that all the nodes are pointing to the root node
        while current_node is not root:
            temp = current_node.parent
            current_node.parent = root
            current_node = temp

        return root.node_id

    # this is how we union 2 disjoint sets
    def merge(self, node1, node2):

        # first we have to find the root nodes
        index1 = self.find(node1)
        index2 = self.find(node2)

        # these nodes are in the same disjoint set
        if index1 == index2:
            return

        # we have to merge by the rank parameters
        root1 = self.root_nodes[index1]
        root2 = self.root_nodes[index2]

        if root1.rank < root2.rank:
            root1.parent = root2
        elif root1.rank > root2.rank:
            root2.parent = root1
        else:
            root2.parent = root1
            root1.rank = root1.rank + 1

    def make_sets(self):
        for v in self.vertex_list:
            node = Node(0, len(self.root_nodes))
            v.node = node
            self.root_nodes.append(node)


class KruskalAlgorithm:

    def __init__(self, vertex_list, edge_list):
        self.vertex_list = vertex_list
        self.edge_list = edge_list

    def find_mst(self):

        disjoint_set = DisjointSet(self.vertex_list)
        mst = []

        # MST algorithm
        # sort the edges based on the weight
        self.edge_list.sort()

        # consider the edges in the sorted order
        for edge in self.edge_list:

            u = edge.start_vertex
            v = edge.target_vertex

            # the nodes associated with the u and v vertices are in the same
            # disjoint sets or not (if they share the same root node)
            if disjoint_set.find(u.node) is not disjoint_set.find(v.node):
                mst.append(edge)
                # we have to merge the disjoint sets
                disjoint_set.merge(u.node, v.node)

        for edge in mst:
            print(edge.start_vertex.name, " - ", edge.target_vertex.name, " - ", edge.weight)


if __name__ == '__main__':

    # vertices in the G(V,E)
    vertex1 = Vertex("A")
    vertex2 = Vertex("B")
    vertex3 = Vertex("C")
    vertex4 = Vertex("D")
    vertex5 = Vertex("E")
    vertex6 = Vertex("F")
    vertex7 = Vertex("G")

    # edges
    edge1 = Edge(2, vertex1, vertex2)
    edge2 = Edge(6, vertex1, vertex3)
    edge3 = Edge(5, vertex1, vertex5)
    edge4 = Edge(10, vertex1, vertex6)
    edge5 = Edge(3, vertex2, vertex4)
    edge6 = Edge(3, vertex2, vertex5)
    edge7 = Edge(1, vertex3, vertex4)
    edge8 = Edge(2, vertex3, vertex6)
    edge9 = Edge(4, vertex4, vertex5)
    edge10 = Edge(5, vertex4, vertex7)
    edge11 = Edge(5, vertex6, vertex7)

    # have to create a list out of these edges and vertices
    vertices = [vertex1, vertex2, vertex3, vertex4, vertex5, vertex6, vertex7]
    edges = [edge1, edge2, edge3, edge4, edge5, edge6, edge7, edge8, edge9, edge10, edge11]

    # let's run the algorithm
    algorithm = KruskalAlgorithm(vertices, edges)
    algorithm.find_mst()
