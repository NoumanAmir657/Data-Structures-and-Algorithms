const canJump = (nums) => {
    if (nums.length > 1 && nums[0] === 0){return false}
    if (nums[0] === 0){return true}
    if (nums[0] === 1 && nums[1] === 0){return false}

    let a = nums[0]
    let indexA = 0

    for (let i = 1; i < nums.length-1; ++i){
        if (nums[i] === 0){
            if (indexA + a > i){
                continue
            }
            else{
                return false
            }
        }
        else {
            if (indexA + a < i + nums[i]){
                a = nums[i]
                indexA = i
            }
        }
    }
    return true
}

console.log(canJump([2,3,1,0,4]))
console.log(canJump([3,2,1,0,4]))
console.log(canJump([2,3,0,0,4]))