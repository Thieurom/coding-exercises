#
# LeetCode
# 121. Best Time to Buy and Sell Stock
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0: return 0
        
        max_profit = 0
        min_price = float('inf')
        
        for i in range(len(prices)):
            diff = prices[i] - min_price
            max_profit = max(max_profit, diff)
            min_price = min(min_price, prices[i])

        return max_profit
