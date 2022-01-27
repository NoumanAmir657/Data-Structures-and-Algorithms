// const minCostClimbingStaires = (array, index, totalCost) => {
//     if (index >= array.length){return totalCost}
//     if (index !== -1){totalCost = totalCost + array[index]}
//     return Math.min(sol(array, index+1, totalCost), sol(array, index+2, totalCost))
// }

//top-down approach
const minCostClimbingStaires = (array) => {
    const n = array.length
    const dp = new Array(n).fill(-1)
    dp[0] = array[0]
    dp[1] = array[1]
    return Math.min(minCost(n-1, array, dp), minCost(n-2, array, dp))
}

const minCost = (i, cost, dp) => {
    if (i < 0){return 0}
    if (i === 0 || i === 1){return dp[i]}
    dp[i] = cost[i] + Math.min(dp[i-1] === -1 ? minCost(i-1, cost, dp) : dp[i-1], dp[i-2] === -1 ? minCost(i-2, cost, dp) : dp[i-2])
    return dp[i]
}

//bottom-up approach
const iterativeMinCostClimbingStaires = (array) => {
    const dp = new Array(array.length).fill(0)
    dp[0] = array[0]
    dp[1] = array[1]
    for (let i= 2; i < array.length; ++i){
        dp[i] = array[i] + Math.min(dp[i-1], dp[i-2])
    }
    return Math.min(dp[dp.length-1], dp[dp.length-2])
}

console.log(iterativeMinCostClimbingStaires([1,1,3,5]))
console.log(minCostClimbingStaires([1,1,3,5]))