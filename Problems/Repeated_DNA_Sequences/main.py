from typing import List

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) <= 10:
            return []
        
        m = {}
        for i in range(len(s)):
            if s[i:i+10] in m:
                m[s[i:i+10]] += 1
            else:
                m[s[i:i+10]] = 1
        
        res = []
        for k in m:
            if m[k] > 1:
                res.append(k)
        return res

sol = Solution()
print(sol.findRepeatedDnaSequences('AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'))