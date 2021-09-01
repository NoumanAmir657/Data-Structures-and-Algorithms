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

console.log(maximumWater([7,1,2,3,9]));