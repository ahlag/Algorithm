
matrix = [[1,1,1],[1,0,1],[1,1,1]]

def setZeroes(matrix):
    """
    Do not return anything, modify matrix in-place instead.
    """
    
    R = len(matrix)
    C = len(matrix[0])
    rows, cols = set(), set()
    
    for i in range(R):
        for j in range(C):
            if matrix[i][j] == 0:
                rows.add(i)
                cols.add(j)
                
    for i in range(R):
        for j in range(C):
            if i in rows or j in cols:
                matrix[i][j] = 0
        
    return matrix        
                
print(setZeroes(matrix))