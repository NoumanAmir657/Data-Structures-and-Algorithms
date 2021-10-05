// Time Complexity O(n)
// Space Complexity O(n)
const numberOfIslands = (matrix) => {
    if (matrix.length == 0) {return 0}
    if (matrix[0].length == 0) {return 0}
    
    //const seen = new Array(matrix.length).fill(0).map(() => new Array(matrix[0].length).fill(false))
    const q = [[0,0]]
    let count = 0;
    if (matrix[0][0] == 0){
        q.shift()
        findNonZero(matrix, q)
    }
        while (q.length) {
            const currentPos = q.shift()
            const row = currentPos[0]
            const col = currentPos[1]

/*
            if (check){
                continue
            }
*/
/*
            if(matrix[row][col] == 0){
                findNonZero(matrix, q)
                continue
            }
*/

            //seen[row][col] = true
            matrix[row][col] = 0;
            for (let i = 0; i < directions.length; ++i){
                const currentDir = directions[i]
                if (!check(matrix, row+currentDir[0], col+currentDir[1])){
                    if (matrix[row+currentDir[0]][col+currentDir[1]] != 0){
                        q.push([row+currentDir[0], col+currentDir[1]])
                        matrix[row+currentDir[0]][col+currentDir[1]] = 0
                    }
                }
            }
            if (!q.length){
                ++count;
                findNonZero(matrix, q)
            }
        }


    return count
}

const findNonZero = (matrix, q) => {
    let found = false
    for (let i = 0; i < matrix.length; ++i){
        if (found) {break}
        for (let j = 0; j < matrix[0].length; ++j){
            if (matrix[i][j] != 0){
                q.push([i,j])
                found = true
                break
            }
        }
    }
}

const check = (matrix, row, col) => {
    return row < 0 || col < 0 || row >= matrix.length || col >= matrix[0].length
}

const matrix = [
    [1,1,1,1,0],
    [1,1,0,1,0],
    [1,1,0,0,1],
    [0,0,0,1,1],
]

const matrix2 = [
    [0,1,0,1,0],
    [1,0,1,0,1],
    [0,1,1,1,0],
    [1,0,1,0,1],
]

const directions = [
    [-1, 0],
    [0, 1],
    [1, 0],
    [0, -1]
]

console.log(numberOfIslands(matrix))


/*
const traversalBFS = (matrix) => {
    if (matrix.length == 0) {return 0}
    if (matrix[0].length == 0) {return 0}
    
    const seen = new Array(matrix.length).fill(0).map(() => new Array(matrix[0].length).fill(false))
    const q = [[0,0]]
    let count = 0;
    
        while (q.length) {
            const currentPos = q.shift()
            const row = currentPos[0]
            const col = currentPos[1]


            if (check){
                continue
            }


if(matrix[row][col] == 0){
    findNonZero(matrix, q, seen)
    continue
}

seen[row][col] = true
for (let i = 0; i < directions.length; ++i){
    const currentDir = directions[i]
    if (!check(matrix, seen, row+currentDir[0], col+currentDir[1])){
        if (matrix[row+currentDir[0]][col+currentDir[1]] != 0){
            q.push([row+currentDir[0], col+currentDir[1]])
            seen[row+currentDir[0]][col+currentDir[1]] = true
        }
    }
}
if (!q.length){
    ++count;
    findNonZero(matrix, q, seen)
}
}


return count
}

const findNonZero = (matrix, q, seen) => {
let found = false
for (let i = 0; i < matrix.length; ++i){
if (found) {break}
for (let j = 0; j < matrix[0].length; ++j){
if (!seen[i][j] && matrix[i][j] != 0){
    q.push([i,j])
    found = true
    break
}
}
}
}

const check = (matrix, seen, row, col) => {
return row < 0 || col < 0 || row >= matrix.length || col >= matrix[0].length || seen[row][col]
}
*/