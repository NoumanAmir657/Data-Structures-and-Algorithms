const longestSubsequence = (s1, s2) => {
    const dp = new Array(s1.length).fill(0).map(() => new Array(s2.length).fill(-1))
    return [recursive(s1, s2, 0, 0, dp), printSubsequence(dp, s1, s2)]
}

const recursive = (s1, s2, i, j, dp) => {
    if (i === s1.length || j === s2.length){return 0}
    else if(dp[i][j] >= 0){return dp[i][j]}
    else if (s1[i] === s2[j]){
        dp[i][j] = 1 + recursive(s1, s2, i+1, j+1, dp)
        return dp[i][j]
    }
    else{
        dp[i][j] = Math.max(recursive(s1, s2, i+1, j, dp), recursive(s1, s2, i, j+1, dp))
        return dp[i][j]
    }
}

const printSubsequence = (matrix, s1, s2) => {
    let s = ""
    let i = 0
    let j = 0
    while(1){
        if (i === matrix.length-1){
            ++j
            break
        }
        if (j === matrix[0].length-1){
            ++i
            break
        }
        if (matrix[i][j] > matrix[i+1][j+1]){
            if (matrix[i][j] === matrix[i][j+1]){
                j++
            }
            else{
                s += s2[j]
                i++
                j++
            }
        }
        else {
            j++
        }
    }
    
    for (let c = j; c < matrix[0].length; ++c){
        if (matrix[i][c] === 1){
            s += s2[j]
        }
    }

    return s
}

const s1 = "stone"
const s2 = "longest"
console.log(longestSubsequence(s1, s2))
