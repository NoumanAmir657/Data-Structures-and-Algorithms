const binarySearch = (array, value, startIndex, endIndex) =>{
    let middleIndex = Math.trunc((startIndex+endIndex)/2) 

    if (startIndex <= endIndex){
        if (value > array[middleIndex]){
            return binarySearch(array, value, middleIndex+1, endIndex)
        }
        else if (value < array[middleIndex]){
            return binarySearch(array, value, startIndex, middleIndex-1)
        }
        else {
            return middleIndex
        }
    }
    else {
        return -1;
    }
}


const binarySearchIndex = (target) =>{
    const array = [1,2,3,4,5,6]
    let index = binarySearch(array, target, 0, array.length-1)

    if (index === -1){
        return [-1, -1]
    }

    let temp = index;
    let range = [index]

    while (index !== -1){
        index = binarySearch(array, target, 0, index-1);
        if (index !== -1){
            range[0] = index
        }
    }
    while(temp !== -1){
        temp = binarySearch(array, target, temp+1, array.length-1);
        if (temp !== -1){
            range[1] = temp 
        }
    }

    if (range.length === 1){
        return [range[0], range[0]]
    }

    return range
    
}

console.log(binarySearchIndex(9))