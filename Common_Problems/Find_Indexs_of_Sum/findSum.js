// Time Complexity O(n^2)
// Space Complexity O(1)

// brute force solution
var twoSum = (nums, target) => {
    for (let i = 0; i < nums.length; ++i){
        const numberToFind = target - nums[i];

        for (let j = i+1; j < nums.length; ++j){
            if (numberToFind === nums[j]){
                return [i, j];
            }
        }
    }
    return null;
};

// optimized solution

// Time Complexity O(n)
// Space Complexity O(n)
var optimizedTwoSum = (nums, target) => {
    const numsMap = {};
    
    for (let i = 0; i < nums.length; ++i){
        const currentMapValue = numsMap[nums[i]]

        if (currentMapValue >= 0){
            return [currentMapValue, i]
        }
        else {
            const numberToFind = target - nums[i];
            numsMap[numberToFind] = i
        }
    }
    return null
}

console.log(twoSum([1,3,7,9,2], 11))
console.log(optimizedTwoSum([1,3,7,9,2], 11))