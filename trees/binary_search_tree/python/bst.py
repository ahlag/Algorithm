class Node:
    
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        
class BinarySearchTree:
    
    def __init__(self):
        self.root = None
        
    def insert(self, value):
        
        if self.root is None:
            self.root = Node(value)
        else:
            self.insert_node(value, self.root)
        
    def insert_node(self, value, node):
        
        if value < node.value:
            if node.left:
                self.insert_node(value, node.left)
            else:
                node.left = Node(value)
        else:
            if node.right:
                self.insert_node(value, node.right)
            else:
                node.right = Node(value)
            
    def traverse(self, order):
        
        if self.root:
            if order == 'in_order':
                self.in_order_traversal(self.root)
            elif order == 'pre_order':
                self.pre_order_traversal(self.root)
            elif order == 'post_order':
                self.post_order_traversal(self.root)
                
    def in_order_traversal(self, node):
        
        if node.left:
            self.in_order_traversal(node.left)
            
        print(node.value)
        
        if node.right:
            self.in_order_traversal(node.right)
            
    def pre_order_traversal(self, node):
        
        print(node.value)
        
        if node.left:
            self.pre_order_traversal(node.left)
            
        if node.right:
            self.pre_order_traversal(node.right)
            
    def post_order_traversal(self, node):
        
        if node.left:
            self.post_order_traversal(node.left)
            
        if node.right:
            self.post_order_traversal(node.right)
            
        print(node.value)
        
def main():
    
    binary_search_tree = BinarySearchTree()
    
    binary_search_tree.insert(4)
    binary_search_tree.insert(3)
    binary_search_tree.insert(1)
    binary_search_tree.insert(2)
    binary_search_tree.insert(5)
    
    print('Inorder Traversal')
    binary_search_tree.traverse(order='in_order')
    
    print('Preorder Traversal')
    binary_search_tree.traverse(order='pre_order')
    
    print('Postorder Traversal')
    binary_search_tree.traverse(order='post_order')
    
if __name__ == "__main__":
    main()