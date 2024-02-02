class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def dfs(i, currentSum, total):
            if total == target:
                res.append(currentSum.copy())
                return
            if total > target or i >= len(candidates):
                return

            currentSum.append(candidates[i])
            dfs(i, currentSum, total + candidates[i])

            currentSum.pop()
            dfs(i + 1, currentSum, total)

        dfs(0, [], 0)
        return res            
