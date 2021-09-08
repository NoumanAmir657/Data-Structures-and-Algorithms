// Time Complexity O(size of a + size of b)
// Space Complexity O(size of a + size of b)
// brute force solution
const equalStrings = (a, b) => {
    let finalA = finalForm(a) // Time Complexity O(size of a)
    let finalB = finalForm(b) // Time Complexity O(size of b)

    // check if final form of strings have equal length
    if (finalB.length !== finalA.length){
        return false
    }
    else {
        // for loop to compare each element of array0
        for (let i = 0; i < finalA.length; i++) {
            if (finalA[i] !== finalB[i]){
                return false
            }
        }
        return true
    }
}

const finalForm = (str) => {
    const final = []
    for (let i = 0; i < str.length; i++) {
        if (str[i] === '#' && final.length !== 0){
            final.pop()
        }
        else {
            final.push(str[i])
        }
    }
    return final
}

// Time Complexity O(size of a + size of b)
// Space Complexity O(1)
// optimized solution
const optimizedEqualStrings = (a, b) => {
    let p1 = a.length - 1;
    let p2 = b.length - 1;
    
    while (p1 >= 0 || p2 >=0){
        if (a[p1] === '#' || b[p2] === '#'){
            if (a[p1] === '#'){
                let backCount = 2
                while (backCount > 0){
                    p1--;
                    backCount--;
                    if (a[p1] === '#'){
                        backCount = backCount + 2;
                    }
                }
            }
            else if(b[p2] === '#'){
                let backCount = 2
                while (backCount > 0){
                    p2--;
                    backCount--;
                    if (b[p2] === '#'){
                        backCount = backCount + 2;
                    }
                }
            }
        }
        else {
            if (a[p1] !== b[p2]){
                return false
            }
            else {
                p1--;
                p2--;
            }
        }
    }
    return true
}

console.log(optimizedEqualStrings("Ab#z", "az#z"))
