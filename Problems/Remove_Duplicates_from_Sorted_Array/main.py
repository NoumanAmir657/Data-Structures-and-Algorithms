from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        L = 0
        R = 0


        while L < len(nums):
            count = 0
            while R < len(nums) and nums[L] == nums[R]:
                count += 1
                if count > 2:
                    nums[R] = 'a'
                R += 1
            L = R

        L = 0
        R = 0

        while R < len(nums) and L < len(nums):
            if nums[L] == 'a':
                R = L + 1
                while R < len(nums) and nums[R] == 'a':
                        R += 1
                while R < len(nums) and (nums[L] == 'a' and nums[R] != 'a'):
                    nums[L] = nums[R]
                    nums[R] = 'a'
                    L += 1
                    R += 1
            else:
                L += 1

        count = 0
        for i in nums:
            if i != 'a':
                count += 1
            else:
                return count
        
        return count

sol = Solution()
print(sol.removeDuplicates([1,1,1,2,2,3]))
