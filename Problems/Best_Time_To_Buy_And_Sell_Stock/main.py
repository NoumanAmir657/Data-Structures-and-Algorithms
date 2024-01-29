from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        buy, sell, profit = 0,0,0
        N = len(prices) - 1

        while (i < N):
            while (i < N and prices[i + 1] <= prices[i]): 
                i+=1 
            buy = prices[i]

            while (i < N and prices[i + 1] > prices[i]): 
                i+=1
            sell = prices[i]

            profit += sell - buy
        
        return profit

sol = Solution()
print(sol.maxProfit([7,1,5,3,6,4]))
