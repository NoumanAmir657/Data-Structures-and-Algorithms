const validString = (s) => {
    const array = s.split('')
    if (array.length === 0){
        return s
    }

    const stack = []
    for (let i = 0; i < array.length; ++i){
        if (array[i] === '('){
            stack.push(i)
        }
        else if (array[i] === ')'){
            if (stack.length === 0){
                array[i] = ''
            }
            else {
                stack.pop()
            }
        }
    }

    while (stack.length !== 0){
        array.splice(stack.pop(), 1)
    }

    return array.join('')
}

console.log(validString("(ab(c)d"))