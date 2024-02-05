class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        def isPalindrome(s):
            l = 0
            r = len(s) - 1

            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
                
            return True

        def dfs(current, index):
            if index >= len(s):
                res.append(current.copy())
                return

            for i in range(len(s) - index):
                if isPalindrome(s[index:index+i+1]):
                    current.append(s[index:index+i+1])
                    dfs(current, index+i+1)
                    current.pop()
            
        dfs([], 0)
        return res
