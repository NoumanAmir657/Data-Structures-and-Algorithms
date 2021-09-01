// Time Complexity O(n^2)
// Space Complexity O(1)
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

console.log(twoSum([1,3,7,9,2], 11))