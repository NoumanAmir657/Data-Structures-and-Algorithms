// brute force solution
const longestSubstring = (str) => {
    let i = 0
    let subString = ''
    let length = 0
    let maxLength = 0

    if (str.length === 0 || str.length === 1){
        return str.length
    }

    while (i < str.length) {
        if (subString.includes(str[i])){
            i = i - (subString.length-1)
            subString = ''
            length = 0
        }
        else {
            subString += str[i];
            ++length;
            maxLength = Math.max(maxLength, length)
            ++i;
        }
    }
    return maxLength
}

// Time complexity O(n^2)
// Space complexity O(n)
// brute force solution
const anotherLongestSubstring = (str) => {
    if (str.length <= 1){
        return str.length
    }

    let maxLength = 0;

    for (let i = 0; i < str.length; ++i){
        let seenChars = {}
        let length = 0
        for (let j = i; j < str.length; ++j){
            const currentChar = str[j]

            if (!seenChars[currentChar]){
                length++
                seenChars[currentChar] = true
                maxLength = Math.max(maxLength, length)
            }
            else {
                break
            }
        }
    }

    return maxLength
}


// Time Complexity O(n)
// Space Complexity O(n)
// optimal solution
const optimizedLongestSubstring = (str) => {
    let maxLength = 0;
    let length = 0;
    let i = 0
    let seenChars = {}

    if (str.length <= 1){
        return str.length
    }

    while (i < str.length) {
        if (seenChars[str[i]] || seenChars[str[i]] === 0){
            length = 0;
            i = seenChars[str[i]] + 1
            seenChars = {}
        }
        else {
            seenChars[str[i]] = i
            length++
            maxLength = Math.max(maxLength, length)
            ++i;
        }
    }
    return maxLength
}

console.log(optimizedLongestSubstring("abcabcbb"))