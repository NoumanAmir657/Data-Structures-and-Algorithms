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


const directions = [
    [-2,-1], [-2,1], [-1,2], [1,2], 
    [2,1], [2,-1], [1,-2], [-1,-2]
]

console.log(bruteForceKnightProbability(6, 3, 2, 2))
console.log(topDownKnightProbability(6, 3, 2, 2))