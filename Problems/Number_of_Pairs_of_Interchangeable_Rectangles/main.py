from typing import List

class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        import math

        ratios = {}
        for rect in rectangles:
            ratio = rect[0] / rect[1]
            
            if ratio not in ratios:
                ratios[ratio] = 1
            else:
                ratios[ratio] += 1
        
        result = 0
        for r in ratios:
            if ratios[r] == 1:
                continue
            else:
                result += math.comb(ratios[r], 2)
        
        return result

sol = Solution()
print(sol.interchangeableRectangles([[4,8],[3,6],[10,20],[15,30]]))
