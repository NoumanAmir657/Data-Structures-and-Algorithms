const quickSort = (array, startIndex, endIndex) => {
    if (startIndex < endIndex){
        let pivotIndex = partition(array, startIndex, endIndex)

        quickSort(array, startIndex, pivotIndex-1)
        quickSort(array, pivotIndex+1, endIndex)
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

const kthLargestElement = (array, k) => {
    quickSort(array, 0, array.length-1)

    return array[array.length - k]
}

const array = [25,21,12,40,37,43,14,28]
console.log(kthLargestElement(array, 5))