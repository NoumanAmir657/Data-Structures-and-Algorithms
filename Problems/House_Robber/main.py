class Solution:
    def rob(self, nums: List[int]) -> int:
        p1 = 0
        p2 = 0

        for n in nums:
            x = max(n + p1, p2)
            p1 = p2
            p2 = x

        return p2
