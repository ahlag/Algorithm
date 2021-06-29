
matrix = [[1,1,1],[1,0,1],[1,1,1]]

def setZeroes(matrix):
    """
    :type matrix: List[List[int]]
    :rtype: void Do not return anything, modify matrix in-place instead.
    """
    is_col = False
    R = len(matrix)
    C = len(matrix[0])
    for i in range(R):
        if matrix[i][0] == 0:
            is_col = True
        for j in range(1, C):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
                
    for i in range(1, R):
        for j in range(1, C):
            if matrix[i][0] == 0 or matrix[0][j] == 0:
                matrix[i][j] = 0
                
    if matrix[0][0] == 0:
        for j in range(C):
            matrix[0][j] = 0
                
    if is_col:
        for i in range(R):
            matrix[i][0] = 0
            
    return matrix
            
print(setZeroes(matrix))