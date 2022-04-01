const sort = (array, max, min) => {
    const countingArray = []
    const sortedArray = []

    // initialize to 0
    for (let i = 0; i <= max; ++i){
        countingArray[i] = 0
    }

    // initialize to 0
    for (let i = 0; i <= array.length; ++i){
        sortedArray[i] = 0
    }

    // store number of occurences
    for (let i = 0; i < array.length; ++i){
        countingArray[array[i]]++
    }

    // make cumulative array
    for (let i = 1; i < countingArray.length; ++i){
        countingArray[i] = countingArray[i-1] + countingArray[i]
    }

    // sort
    for (let i = array.length-1; i >= 0; --i){
        sortedArray[countingArray[array[i]]] = array[i]
        countingArray[array[i]]--
    }
    
    return sortedArray
}

const array = [2,5,3,0,2,3,0,3]
const getMax = (array) => {
    let max = array[0]

    for (let i = 1; i < array.length; ++i){
        if (array[i] > max){
            max = array[i]
        }
    }
    return max
}

const getMin = (array) => {
    let min = array[0]

    for (let i = 1; i < array.length; ++i){
        if (array[i] > min){
            min = array[i]
        }
    }
    return min
}

console.log(sort(array, getMax(array), getMin(array)))