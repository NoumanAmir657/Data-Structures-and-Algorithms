// Time Complexity O(n log(n))
// Space Complexity O(n)
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
