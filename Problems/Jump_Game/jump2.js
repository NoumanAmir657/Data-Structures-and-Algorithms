const jump = (nums) => {
    const distance = []
    for (let i = 0; i < nums.length; ++i){
        if (nums[i] === 0){distance[i] = 0}
        else{
            distance[i] = i + nums[i]
        }
    }

    let i = 0
    let jumps = 0
    while (i < distance.length-1){
        let max = -Infinity
        let maxIndex = -Infinity
        let coverDistance = distance[i]
        if (coverDistance >= distance.length-1){
            ++jumps
            break
        }
        for (let j = i+1; j <= coverDistance; ++j){
            if (distance[j] > max){
                max = distance[j]
                maxIndex = j
            }
        }
        i = maxIndex
        ++jumps
    }
    return jumps
}

// console.log(canJump([2,3,1,0,4]))
// console.log(canJump([3,2,1,0,4]))
// console.log(canJump([2,3,0,0,4]))
console.log(jump([2,3,1,1,4]))
console.log(jump([2,3,0,1,4]))
console.log(jump([5,7,3,2,1,0,2,3,3,1,0,0]))
console.log(jump([1,1,2,1,1]))
console.log(jump([1,1,1,1]))