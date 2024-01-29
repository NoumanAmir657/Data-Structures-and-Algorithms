class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        done = {}
        count = 0

        for i in range(len(s)):
            if s[i] in done:
                continue
            # get last postion

            j = len(s) - 1
            lastPos = i
            while s[j] != s[i]:
                j -= 1
            lastPos = j
            done[s[i]] = True
            
            if i != j:
                count += len(set(s[i+1:j]))
            
        return count

sol = Solution()
print(sol.countPalindromicSubsequence('aabca'))
