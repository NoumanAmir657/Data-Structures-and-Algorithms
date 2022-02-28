// const deleteAndEarn = (nums) => {
//     let maxScore = -Infinity
//     let seen = {}
//     for(let i = 0; i < nums.length; ++i){
//         if (seen[nums[i]]){
//             maxScore = seen[nums[i]]
//         }
//         else{
//             let score = nums[i]
//             const newArray = remove(nums, nums[i], i) // [2,4,5]
//             score = score + recursiveUtil(newArray)
//             maxScore = Math.max(maxScore, score)
//             seen[nums[i]] = maxScore
//         }
//     }
//     return maxScore
// }

// const recursiveUtil = (array) => {
//     let seen = {}
//     if (array.length === 0){return 0}
//     let maxScore = -Infinity
//     for (let i = 0; i < array.length; ++i){
//         if (seen[array[i]]){
//             maxScore = seen[array[i]]
//         }
//         else{
//             let score = array[i]
//             const newArray = remove(array, array[i], i)
//             score = score + recursiveUtil(newArray)
//             maxScore = Math.max(score, maxScore)
//             seen[array[i]] = maxScore
//         }
//     }
//     return maxScore
// }

// const remove = (array, value, index) => {
//     const newArray = []
//     for (let i = 0; i < array.length; ++i){
//         if (array[i]+1 === value || array[i]-1 === value || i === index){
//             continue
//         }
//         else{
//             newArray.push(array[i])
//         }
//     }
//     return newArray
// }

const deleteAndEarn = (nums) => {
    if(nums.length === 1){return nums[0]}
    const newNums = removeDuplicates(nums)
    newNums.sort((x,y) => x-y)
    const frequencyObject = getFrequencyObject(nums)
    let a = newNums[0] * frequencyObject[newNums[0]]
    let b
    if (newNums[1]-1 === newNums[0]){
        b = Math.max(newNums[1] * frequencyObject[newNums[1]], a)
    }
    else{
        b = a + newNums[1] * frequencyObject[newNums[1]]
    }

    let temp
    for (let i = 2; i < newNums.length; ++i){
        if (newNums[i] - 1 === newNums[i-1]){
            temp = Math.max(frequencyObject[newNums[i]]*newNums[i] + a, b)
        }
        else{
            temp = b + frequencyObject[newNums[i]]*newNums[i]
        }
        a = b
        b = temp
    }
    return b
}

const getFrequencyObject = (nums) => {
    const frequencyObject = {}
    for (let i = 0; i < nums.length; ++i){
        if (frequencyObject[nums[i]]){
            frequencyObject[nums[i]] = frequencyObject[nums[i]] + 1
        }
        else{
            frequencyObject[nums[i]] = 0
            frequencyObject[nums[i]] = frequencyObject[nums[i]] + 1
        }
    }
    return frequencyObject
}

const removeDuplicates = (nums) => {
    return [...new Set(nums)]
}

console.log(deleteAndEarn([1,3,4,4,5,5,5,7,9]))
console.log(deleteAndEarn([2,3,4]))
console.log(deleteAndEarn([8,10,4,9,1,3,5,9,4,10]))


