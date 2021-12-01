// Time complexity O(n^2)
// Space Complexity O(1)
// Brute force solution
const findMaxWater = (array) => {
    let totalWater = 0;
    let maxR = 0;
    let maxL = 0;

    for (let current = 0; current < array.length; ++current){
        maxL = 0;
        maxR = 0;
        for (let j = current-1; j >= 0; --j){
            maxL = Math.max(array[j], maxL);
        }
        for (let k = current+1; k < array.length; ++k){
            maxR = Math.max(array[k], maxR);
        }
        let currentWater = Math.min(maxL, maxR) - array[current];
        if (currentWater >= 0){
            totalWater = totalWater + currentWater;
        }
    }
    return totalWater;
}

// Time Complexity O(n)
// Space Complexity O(1)
// Optimized solution
const optimizedFindMaxWater = (array) => {
    let totalWater = 0;
    let maxR = 0; // stores largest value on right hand side of array
    let maxL = 0; //stores largest value on left hand side of array
    let pL = 0; // left pointer
    let pR = array.length; // right pointer

    while (pL !== pR){
        // left pointer has value which is less than or equal to right pointer value
        if (array[pL] <= array[pR]){
            if (array[pL] <= maxL){
                totalWater = totalWater + (maxL-array[pL]);
            }
            else {
                maxL = array[pL];
            }
            ++pL;
        }
        // right pointer has value which is less than left pointer value
        else {
            if (array[pR] <= maxR){
                totalWater = totalWater + (maxR-array[pR]);
            }
            else {
                maxR = array[pR];
            }
            --pR;
        }
    }
    return totalWater;
}

console.log(optimizedFindMaxWater([0,1,0,2,1,0,3,1,0,1,2]))
console.log(optimizedFindMaxWater([5,0,3,0,0,0,2,3,4,2,1]))