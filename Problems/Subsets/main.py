class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        currentSubset = []

        def dfs(i):
            if i >= len(nums):
                res.append(currentSubset.copy())
                return
            
            currentSubset.append(nums[i])
            dfs(i + 1)

            currentSubset.pop()
            dfs(i + 1)

        dfs(0)
        return res
