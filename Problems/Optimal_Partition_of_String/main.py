class Solution:
    def partitionString(self, s: str) -> int:
        i = 0
        count = 0
        while i < len(s):
            letters = set()
            letters.add(s[i])
            i += 1

            while i < len(s) and s[i] not in letters:
                letters.add(s[i]) 
                i += 1
            
            count += 1
        
        return count
    
sol = Solution()
print(sol.partitionString('abacaba'))