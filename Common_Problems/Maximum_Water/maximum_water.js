// Time complexity O(n^2)
// Space complexity O(1)
// brute force
const maximumWater = (array) => {
    let maxArea = 0;

    for (let i = 0; i < array.length; ++i){
        for(let j = i+1; j < array.length; ++j){
            let area = Math.min(array[i], array[j]) * (j-i) 
            maxArea = Math.max(area, maxArea);
        }
    }
    return maxArea;
}

// Time complexity O(n)
// Space complexity O(1)
// optimized solution
const optimizedMaximumWater = (array) => {
    let maxArea = 0;
    let a = 0;
    let b = array.length - 1;

    for (let i = 0; i < array.length-1; ++i){
        let area = Math.min(array[a], array[b]) * (b - a);
        maxArea = Math.max(area, maxArea);
        if (a < b){
            ++a;
        }
        else {
            ++b;
        }
    }
    return maxArea
}

console.log(optimizedMaximumWater([4,1,8,2,3,9]));
