const gatesAndWalls = (matrix) => {
    if (matrix.length == 0){
        return matrix
    }
    if (matrix[0].length == 0){
        return matrix
    }

    let q = []
    gates = findGates(matrix)

    for (let i = 0; i < gates.length; ++i){
        q.push(gates[i])
        while (q.length){
            const currentPos = q.shift()
            const row = currentPos[0]
            const col = currentPos[1]

            for (let d = 0; d < directions.length; ++d){
                const tempR = row + directions[d][0]
                const tempC = col + directions[d][1]
                if (!(tempR < 0 || tempC < 0 || tempR >= matrix.length || tempC >= matrix[0].length)){
                    if (matrix[tempR][tempC] != -1 && matrix[tempR][tempC] != 0){
                        if (matrix[row][col] < matrix[tempR][tempC]){
                            matrix[tempR][tempC] = matrix[row][col] + 1
                            q.push([tempR,tempC])
                        }
                    }
                }
            }
        }
    }
    return matrix
}

const findGates = (matrix) => {
    const gates = []
    for (let i = 0; i < matrix.length; ++i){
        for (let j = 0; j < matrix[0].length; ++j){
            if (matrix[i][j] === 0){
                gates.push([i,j])
            }
        }
    }
    return gates;
}

const matrix = [
    [Infinity, -1, 0, Infinity],
    [Infinity, Infinity, Infinity, -1],
    [Infinity, -1, Infinity, -1],
    [0, -1, Infinity, Infinity],
]

const matrix2 = [
    [Infinity, -1, 0, Infinity],
    [-1, Infinity, Infinity, -1],
    [Infinity, -1, Infinity, -1],
    [0, -1, Infinity, Infinity],
]

const directions = [
    [-1, 0],
    [0, 1],
    [1, 0],
    [0, -1]
]

console.log(gatesAndWalls(matrix2))