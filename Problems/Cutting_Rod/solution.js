const maxRevenue = (costArray, n) => {
    const dp = new Array(n+1).fill(0)
    dp[1] = costArray[1]
    dp[2] = costArray[2]

    for (let i = 3; i <= n; ++i){
        let max = costArray[i]
        for (let j = i-1; j > 0; --j){
            max = Math.max(max, dp[j] + dp[i-j])
        }
        dp[i] = max
    }
    return dp[n]
}

const costArray = [0,1,5,8,9,10,17,17,20,24,30]
console.log(maxRevenue(costArray, 10))