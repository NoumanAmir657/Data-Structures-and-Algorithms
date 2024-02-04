class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        current = []
        nums = sorted(nums)

        def dfs(i):
            if i >= len(nums):
                res.append(current.copy())
                return
            
            current.append(nums[i])
            dfs(i + 1)
            current.pop()
            while i+1 < len(nums) and nums[i+1] == nums[i]:
                i += 1
            dfs(i+1)
        
        dfs(0)
        return res
