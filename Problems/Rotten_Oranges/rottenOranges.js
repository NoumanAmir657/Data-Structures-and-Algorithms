const directions = [
    [-1,0]
    [0,1]
    [1,0]
    [0,-1]
]

const ROTTEN = 2
const FRESH = 1
const EMPTY = 0

// Time Complexity O(n)
// Space Complexity O(n)
const orangesRotting = (matrix) => {
    if (matrix.length === 0) {return 0}
    
    const q = []
    let freshOranges = 0
    
    for (let i = 0; i < matrix.length; ++i){
        for (let j = 0; j < matrix[0].length; ++j){
            if (matrix[i][j] === FRESH){
                ++freshOranges
            }
            else if (matrix[i][j] === ROTTEN){
                q.push([i][j])
            }
        }
    }

    let currentQSize = q.length
    let minutes = 0;

    while (q.length > 0) {
        if (currentQSize === 0){
            minutes++
            currentQSize = q.length
        }
        const curretOrange = q.shift()
        currentQSize--
        const row = curretOrange[0]
        const col = curretOrange[1]

        for (let i = 0; i < directions.length; ++i){
            const currentDir = directions[i]
            const nextRow = currentDir[0] + row
            const nextCol = currentDir[1] + col

            if (nextRow < 0 || nextRow >= matrix.length || nextCol < 0 || nextCol >= matrix[0].length){
                continue
            }
            if(matrix[nextRow][nextCol] === FRESH){
                matrix[nextRow][nextCol] = 2
                freshOranges--
                q.push([nextRow, nextCol])
            }
        }
    }

    if (freshOranges > 0){
        return -1
    }
    return minutes
}