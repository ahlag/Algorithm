class union_find:

    def __init__(self, no_of_nodes):
        self.parents = [i for i in range(no_of_nodes)]
        
    def union(self, x, y):
        self.parents[x] = self.find(y)

    def find(self, x):
        
        if self.parents[x] == x:
            return self.parents[x]
        else:
            return self.find(self.parents[x])
        
def main():
    
    uf = union_find(100)
    
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