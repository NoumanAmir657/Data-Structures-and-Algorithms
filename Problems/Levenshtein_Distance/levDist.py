import numpy as np

s1 = input("Enter string 1: ")
s2 = input("Enter string 2: ")

matrix = np.zeros((len(s2) + 1, len(s1) + 1))

for r in range(matrix.shape[0]):
    matrix[r, 0] = r

for c in range(matrix.shape[1]):
    matrix[0, c] = c

for r in range(1, matrix.shape[0]):
    for c in range(1, matrix.shape[1]):
        if s1[c-1] == s2[r-1]:
            matrix[r,c] = matrix[r-1,c-1]
        else:
            matrix[r,c] = min(matrix[r - 1, c] + 1, matrix[r, c - 1] + 1, matrix[r - 1, c - 1] + 1)

print(matrix)

#backtrack

currentR = matrix.shape[0] - 1
currentC = matrix.shape[1] - 1
currentVal = matrix[currentR, currentC]

ins = 0
dels = 0
subs = 0

while currentVal != 0:
    up = matrix[currentR - 1, currentC]         # insertion
    left = matrix[currentR, currentC - 1]       # deletion
    diag = matrix[currentR - 1, currentC - 1]   # subsitution

    minVal = min([up, left, diag])
    minIndex = [up, left, diag].index(minVal)

    if minIndex == 0:
        currentR -= 1
        ins = ins + 1 if currentVal - matrix[currentR, currentC] > 0 else ins
    elif minIndex == 1:
        currentC -= 1
        dels = dels + 1 if currentVal - matrix[currentR, currentC] > 0 else dels
    else:
        currentR -= 1
        currentC -= 1
        subs = subs + 1 if currentVal - matrix[currentR, currentC] > 0 else subs
    
    currentVal = matrix[currentR, currentC]

print("\nLevenshtein Distance: " + str(int(matrix[matrix.shape[0] - 1, matrix.shape[1] - 1])))
print("Number of subsitution: ", subs)
print("Number of insertions: ", ins)
print("Number of deletions: ", dels)