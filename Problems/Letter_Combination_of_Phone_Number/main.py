class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        numberToLetters = {
            2: ['a', 'b', 'c'],
            3: ['d', 'e', 'f'],
            4: ['g', 'h', 'i'],
            5: ['j', 'k', 'l'],
            6: ['m', 'n', 'o'],
            7: ['p', 'q', 'r', 's'],
            8: ['t', 'u', 'v'],
            9: ['w', 'x', 'y', 'z'],
        }

        res = []

        def dfs(current, index):
            if index >= len(digits):
                res.append(''.join(current.copy()))
                return
            
            for letter in numberToLetters[int(digits[index])]:
                current.append(letter)
                dfs(current, index + 1)
                current.pop()
        
        dfs([], 0)
        return res
