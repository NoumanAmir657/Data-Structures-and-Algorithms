from typing import List

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        sI = -1
        eI = -1
        count = 0
        i = 0
        while i < len(nums):
            if nums[i] == 0:
                sI = i
                eI = i
                i += 1
                while i < len(nums) and nums[i] == 0:
                    eI = i
                    i += 1
                
                length = eI - sI + 1
                count += sum([n for n in range(1, length + 1)])
            else:
                i += 1
        return count
    
sol = Solution()
print(sol.zeroFilledSubarray([1,3,0,0,2,0,0,4]))