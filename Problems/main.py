class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(current, i):
            if len(current) == len(nums):
                res.append(current.copy())
                return
            for k, n in enumerate(nums):
                if n not in current:
                    current.append(n)
                    dfs(current, k)
                    current.pop()
            
        dfs([], -1)
        return res
