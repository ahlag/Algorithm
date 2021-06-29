import unittest

def rotate_matrix(matrix):
    n = len(matrix)
    for layer in range(n // 2):
        first, last = layer, n - layer - 1
        for i in range(first, last):
            offset = i - first
            # save top
            top = matrix[first][i]

            # left -> top
            matrix[first][i] = matrix[last - offset][first]

            # bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset]

            # right -> bottom
            matrix[last][last - offset] = matrix[i][last]

            # top -> right
            matrix[i][last] = top
    
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