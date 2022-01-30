//brute force solution
//Time Complexity O(2^n)
//Space Complexity O(2^n)
const bruteMinCostClimbingStaires = (array, index, totalCost) => {
    if (index >= array.length){return totalCost}
    if (index !== -1){totalCost = totalCost + array[index]}
    return Math.min(sol(array, index+1, totalCost), sol(array, index+2, totalCost))
}

//top-down approach
//Time Complexity O(n)
//Space Complexity O(n)
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
//Time Complexity O(n)
//Space Complexity O(n)
const iterativeMinCostClimbingStaires = (array) => {
    const dp = new Array(array.length).fill(0)
    dp[0] = array[0]
    dp[1] = array[1]
    for (let i= 2; i < array.length; ++i){
        dp[i] = array[i] + Math.min(dp[i-1], dp[i-2])
    }
    return Math.min(dp[dp.length-1], dp[dp.length-2])
}

//bottom-up approach
//further optimized
//Time Complexity O(n)
//Space Complexity O(1)
const optimizedIterativeMinCostClimbingStaires = (array) => {
    const dp = new Array(array.length).fill(0)
    let count = 0
    dp[0] = array[0]
    dp[1] = array[1]
    for (let i= 2; i < array.length; ++i){
        if (count === 0){
            dp[0] = array[i] + Math.min(dp[0], dp[1])
            count = 1
        }
        else {
            dp[1] = array[i] + Math.min(dp[0], dp[1])
            count = 0
        }
        
    }
    return Math.min(dp[0], dp[1])
}

console.log(iterativeMinCostClimbingStaires([1,1,3,5]))
console.log(minCostClimbingStaires([1,1,3,5]))
console.log(optimizedIterativeMinCostClimbingStaires([1,1,3,5]))