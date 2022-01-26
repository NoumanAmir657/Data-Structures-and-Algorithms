#Strassen's Algorithm conditions
# 1. Both inputs matrices should be of dimensions n x n
# 2. n should be power of 2

import numpy as np

def generateSubmatrices(matrix):
    row, col = matrix.shape
    subRow, subCol = row//2,col//2
    return matrix[:subRow, :subCol], matrix[:subRow, subCol:], matrix[subRow:, :subCol], matrix[subRow:, subCol:]

def strassenMultiply(A, B):
    # Base case
    if len(A) == 1:
        return A*B
    
    # Generating submatrices
    A11, A12, A21, A22 = generateSubmatrices(A)
    B11, B12, B21, B22 = generateSubmatrices(B)

    # Compute the 7 products recursively
    P1 = strassenMultiply(A11, B12 - B22)
    P2 = strassenMultiply(A11 + A12, B22)
    P3 = strassenMultiply(A21 + A22, B11)
    P4 = strassenMultiply(A22, B21 - B11)
    P5 = strassenMultiply(A11 + A22, B11 + B22)
    P6 = strassenMultiply(A12 - A22, B21 + B22)
    P7 = strassenMultiply(A11 - A21, B11 + B12)

    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P1 + P5 - P3 - P7

    C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))

    return C


A = np.array([[1,2,9,10],
            [5,2,3,4],
            [20,8,4,4],
            [5,2,1,4]])

B = np.array([[1,2,3,4],
            [4,5,6,7],
            [8,9,10,11],
            [12,13,14,15]])


print(strassenMultiply(A, B))