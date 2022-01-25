const maxSubArray = (array) => {
    let currentSum = array[0]
    let maxSum = array[0]

    for (let i = 1; i < array.length; ++i){
        currentSum = Math.max(array[i], currentSum + array[i])
        maxSum = Math.max(currentSum, maxSum)
    }
    return maxSum
}

let array = [13, -3, -25, 20, -3, -16, -23, 18, 21, -7]
let array1 = [13, -3, -25, 20, -1, -1, -2, 18, 20, -7]
let array2 = [-2,1,-3,4,-1,2,1,-5,4]
let array3 = [3,-1,-2,3,-2,5,-5,4]
let array4 = [1,2,-1,-2,2,1,-2,1,4,-5,4]
let array5 = [6,-7,-4,4,5,9,7,2,0,-8,1,-5,9,7]

console.log(maxSubArray(array))
console.log(maxSubArray(array1))
console.log(maxSubArray(array2))
console.log(maxSubArray(array3))
console.log(maxSubArray(array4))
console.log(maxSubArray(array5))


