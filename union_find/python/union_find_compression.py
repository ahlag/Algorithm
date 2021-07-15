## Credit to https://github.com/ryancheunggit/leetcode/blob/rise/note/union_find.md
class UnionFind:
    
    def __init__(self, n):
        self.parents = [i for i in range(n)]
        self.sizes = [1] * n
        
    def find(self, x):
        
        # 1 path to find the root
        root = x
        
        while root != self.parents[root]:
            root = self.parents[root]
        
        # 2 path to assign every node in the path to points at root
        while self.parents[x] != root:
            parent = self.parents[x]
            self.parents[x] = root
            x = parent

        return root
    
    def union(self, x, y):
        
        root_x, root_y = map(self.find, (x, y))
        
        if root_x == root_y:
            return
        
        small, big = sorted( [root_x, root_y], key=lambda x: self.sizes[x])
        
        self.parents[small] = big
        self.sizes[big] += self.sizes[small] 
        
def main():
    
    uf = UnionFind(100)
    
    print('---------------------')
    
    print(1, ' belongs to ', uf.find(1))
    print(3, ' belongs to ', uf.find(3))
    
    print('---------------------')
    print('-----UNION(1,3)------')
    uf.union(1, 3)
    
    print(1, ' belongs to ', uf.find(1))
    print(3, ' belongs to ', uf.find(3))
    
    print('---------------------')
    print('-----UNION(2,3)------')
    uf.union(2, 3)
    
    print(1, ' belongs to ', uf.find(1))
    print(2, ' belongs to ', uf.find(2))
    print(3, ' belongs to ', uf.find(3))
    print('---------------------')
    
    print('---------------------')
    print('-----UNION(4,5)------')
    uf.union(4, 5)
    
    print(1, ' belongs to ', uf.find(1))
    print(2, ' belongs to ', uf.find(2))
    print(3, ' belongs to ', uf.find(3))
    print(4, ' belongs to ', uf.find(4))
    print(5, ' belongs to ', uf.find(5))
    print('---------------------')
    
    print('---------------------')
    print('-----UNION(3,4)------')
    uf.union(3, 4)
    
    print(1, ' belongs to ', uf.find(1))
    print(2, ' belongs to ', uf.find(2))
    print(3, ' belongs to ', uf.find(3))
    print(4, ' belongs to ', uf.find(4))
    print(5, ' belongs to ', uf.find(5))
    print('---------------------')
    
if __name__ == "__main__":
    main()