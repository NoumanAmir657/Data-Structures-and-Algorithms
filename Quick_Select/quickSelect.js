const quickSelect = (array, startIndex, endIndex, k) => {
    if (startIndex < endIndex){
        let pivotIndex = partition(array, startIndex, endIndex)

        if (pivotIndex > k){
            quickSelect(array, startIndex, pivotIndex-1, k)
        }
        else if (pivotIndex < k){
            quickSelect(array, pivotIndex+1, endIndex, k)
        }
        return array[k]
    }
}

const partition = (array, startIndex, endIndex) => {
    let pivot = array[startIndex]

    let middleIndex = startIndex

    for (let i = startIndex+1; i <= endIndex; ++i){
        if (array[i] < pivot){
            ++middleIndex

            let temp = array[i]
            array[i] = array[middleIndex]
            array[middleIndex] = temp
        }
    }

    let temp = array[startIndex]
    array[startIndex] = array[middleIndex]
    array[middleIndex] = temp

    return middleIndex
}

const kthSmallestElement = (array, k) => {
    return quickSelect(array, 0, array.length-1, k) 
}

const array = [25,21,12,40,37,43,14,28]
console.log(kthSmallestElement(array, 5))
console.log(array)