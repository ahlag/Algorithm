import unittest

def rotate_matrix(matrix):
    
    N = len(matrix)
    
    ## Transpose
    for i in range(N):
            for j in range(i, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            
    ## Reflect
    for i in range(N):
            for j in range(N//2):
                matrix[i][j], matrix[i][N - 1 - j] = matrix[i][N - 1 - j], matrix[i][j]
    
    return matrix
    
class Test(unittest.TestCase):
    def test_rotate_matrix(self):
        mat1 = [[1,2],[3,4]]
        mat2 = [[3,1],[4,2]]
        self.assertEqual(rotate_matrix(mat1), mat2)
        mat3 = [[1,2,3],[4,5,6],[7,8,9]]
        mat4 = [[7,4,1],[8,5,2],[9,6,3]]
        self.assertEqual(rotate_matrix(mat3), mat4)
        mat5 = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
        mat6 = [[13,9,5,1],[14,10,6,2],[15,11,7,3],[16,12,8,4]]
        self.assertEqual(rotate_matrix(mat5), mat6)

unittest.main()