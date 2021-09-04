// Time complexity O(n^2)
// Space Complexity O(1)
// brute force solution
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

console.log(findMaxWater([0,1,0,2,1,0,3,1,0,1,2]))
console.log(findMaxWater([5,0,3,0,0,0,2,3,4,2,1]))