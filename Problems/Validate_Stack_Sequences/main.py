class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        l = 0
        r = 0
        stack = []

        while (l < len(pushed)):
            if (pushed[l] != popped[r]):
                stack.append(pushed[l])
                l = l + 1
            else:
                l = l + 1
                r = r + 1
                while r < len(popped) and len(stack) != 0 and stack[-1] == popped[r]:
                    stack.pop()
                    r = r + 1
        
        while (len(stack) != 0):
            if (popped[r] == stack[-1]):
                stack.pop()
                r = r + 1
            else:
                return False
        
        return True
