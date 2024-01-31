class Solution:
    def check(self, count, complete):
        for c1, c2 in zip(count, complete):
            if count[c1] > complete[c2]:
                return False
        return True

    def minWindow(self, s, t):
        l = 0
        r = 0
        minL = -1
        minR = -1
        minLength = float('inf')
        
        count = {}
        for c in t:
            if c in count:
                count[c] += 1
            else:
                count[c] = 1
        
        # sum_count = sum(list(count.values()))
        complete = {}
        for c in list(count.keys()):
            complete[c] = 0
        
        while r < len(s):
            if s[r] in complete:
                complete[s[r]] += 1
            
            # sum_complete = sum(list(complete.values()))
            
            while (self.check(count, complete)):
                if (r - l + 1) < minLength:
                    minLength = r - l + 1
                    minL = l
                    minR = r
                
                if s[l] in complete:
                    # sum_complete -= 1
                    complete[s[l]] -= 1
                l += 1
            
            r += 1
        
        return s[minL:minR+1]

sol = Solution()
print(sol.minWindow('ADOBECODEBANC', 'ABC'))