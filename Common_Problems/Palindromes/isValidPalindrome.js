const isValidPalindrome = (s) => {
    s = s.replace(/[^A-Za-z0-9]/g, '').toLowerCase();
    let p1 = 0, p2 = s.length - 1;
    
    while(p1 !== p2){
        if (s[p1] === s[p2]){
            ++p1;
            --p2;
        }
        else {
            return false
        }
    }

    return true
}

const isValidPalindrome2 = (s) => {
    s = s.replace(/[^A-Za-z0-9]/g, '').toLowerCase();
    let left, right

    if ((s.length % 2) === 0){
        left = Math.floor(s.length/2 - 1);
        right = Math.floor(s.length/2);
    }
    else {
        left = Math.floor(s.length/2);
        right = left
    }

    while (left > 0 && right < s.length){
        if (s[left] === s[right]){
            left--;
            right++;
        }
        else {
            return false
        }
    }

    return true
}

const isValidPalindrome3 = (s) => {
    s = s.replace(/[^A-Za-z0-9]/g, '').toLowerCase();

    let reverseString = '';
    let p1 = 0;

    for (let i = s.length-1; i >= 0; i--) {
        reverseString += s[i]
    }

    while (p1 < s.length) {
        if (s[p1] === reverseString[p1]) {
            ++p1
        }
        else {
            return false
        }
    }
    return true
}

console.log(isValidPalindrome3("A man, a plan, a canal: Panama"));

// A man, a plan, a canal: Panama