class Solution:
    def minSwaps(self, s: str) -> int:
        stack = []
        for c in s:
            if not stack:
                stack.append(c)
            else:
                if c == ']' and stack[-1] == '[':
                    stack.pop()
                else:
                    stack.append(c)
        
        half = int(len(stack) / 2)
        if (half % 2) == 0:
            return int(half / 2)
        else:
            return int(half / 2) + 1

sol = Solution()
print(sol.minSwaps('][]['))
