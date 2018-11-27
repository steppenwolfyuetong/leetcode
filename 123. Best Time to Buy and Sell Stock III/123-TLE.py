# Say you have an array for which the ith element is the price of a given stock on day i.
# Design an algorithm to find the maximum profit. You may complete at most two transactions.
# You may not engage in multiple transactions at the same time
# (ie, you must sell the stock before you buy again).


# TLE
# O(n^2)
# 考虑优化

class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        ans = 0
        # 两次交易 分两个区间 [0:i]为第一次交易所在区间 [i:]为第二次 分别求每一次交易的最大利润
        for i in range(1,len(prices)):
            ans = max(ans,self.profit(prices[0:i])+self.profit(prices[i:]))
        return ans

    def profit(price):
        # dp[i]表示第i天卖出的最大利润
        if len(price) == 1:
            return 0
        dp = [0] * len(price)
        for i in range(1,len(price)):
            dp[i] = dp[i-1] + (price[i] - price[i-1])
        return max(dp)

a = [1,2,3,2,1,4,7]
print(Solution.maxProfit(Solution,a))

