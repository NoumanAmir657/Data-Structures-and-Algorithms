//brute force
//Time Complexity O(8^k)
//Space Complexity O(8^k)
const bruteForceKnightProbability = (n, k, r, c) => {
    if (r < 0 || c < 0 || r >= n || c >= n){
        return 0
    }
    if (k === 0){
        return 1
    }
    let probabilitySum = 0
    for (let i = 0; i < directions.length; ++i){
        const dir = directions[i]
        probabilitySum += bruteForceKnightProbability(n, k-1, r+dir[0], c+dir[1])/8
    }
    return probabilitySum
}

//top-down
//Time Complexity O(n^2 * k)
//Space Complexity O(n^2 * k)
const topDownKnightProbability = (n, k, r, c) => {
    const dp = new Array(k+1).fill(0).map(() => new Array(n).fill(0).map(() => new Array(n).fill(undefined)))
    return recursiveUtil(n, k, r, c, dp)
}

const recursiveUtil = (n, k, r, c, dp) => {
    if (r < 0 || c < 0 || r >= n || c >= n){
        return 0
    }
    if (k === 0){
        return 1
    }
    if (dp[k][r][c] != undefined){return dp[k][r][c]}
    let probabilitySum = 0
    for (let i = 0; i < directions.length; ++i){
        const dir = directions[i]
        probabilitySum += bruteForceKnightProbability(n, k-1, r+dir[0], c+dir[1])/8
    }
    dp[k][r][c] = probabilitySum
    return dp[k][r][c]
}

//bottom-up
//Time Complexity O(n^2 * k)
//Space Complexity O(n^2)
const bottomUpKnightProbability = (n, k, r, c) => {
    //const dp = new Array(k+1).fill(0).map(() => new Array(n).fill(0).map(() => new Array(n).fill(0)))
    let prevGrid = new Array(n).fill(0).map(() => new Array(n).fill(0))
    let currentGrid = new Array(n).fill(0).map(() => new Array(n).fill(0))
    //dp[0][r][c] = 1
    prevGrid[r][c] = 1
    for (let i = 1; i <= k; ++i){
        currentGrid = new Array(n).fill(0).map(() => new Array(n).fill(0))
        for (let row = 0; row < n; ++row){
            for(let col = 0; col < n; ++col){
                for (let d = 0; d < directions.length; ++d){
                    const dir = directions[d]
                    const prevRow = row + dir[0]
                    const prevCol = col + dir[1]
                    if (prevRow >= 0 && prevRow < n && prevCol >= 0 && prevCol < n){
                        //dp[i][row][col] += dp[i-1][prevRow][prevCol]/8
                        currentGrid[row][col] += prevGrid[prevRow][prevCol]/8
                    }
                }
            }
        }
        prevGrid = currentGrid
    }
    let probabilitySum = 0
    for (let i = 0; i < n; ++i){
        for (let j = 0; j < n; ++j){
            probabilitySum += currentGrid[i][j]
        }
    }
    return probabilitySum
}


const directions = [
    [-2,-1], [-2,1], [-1,2], [1,2], 
    [2,1], [2,-1], [1,-2], [-1,-2]
]

console.log(bruteForceKnightProbability(6, 3, 2, 2))
console.log(topDownKnightProbability(6, 3, 2, 2))
console.log(bottomUpKnightProbability(6, 3, 2, 2))