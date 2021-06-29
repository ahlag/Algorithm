import unittest

def rotate_matrix(matrix):
    n = len(matrix[0])
    for i in range(n // 2 + n % 2):
        for j in range(n // 2):
            tmp = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i]
            matrix[j][n - 1 - i] = matrix[i][j]
            matrix[i][j] = tmp
    
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