 # * dp[i, j] represents the max profit up until prices[j] using at most i transactions.
 # * dp[i, j] = max(dp[i, j-1], prices[j] - prices[k] + dp[i-1, k]) {0 <= k < j}
 # *          = max(dp[i, j-1], prices[j] + max(dp[i-1, k] - prices[k]))
 # * dp[0, j] = 0; 0 transactions makes 0 profit
 # * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.

class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
            return 0
        if k >= len(prices) // 2:
            rt = 0
            for i in range(1,len(prices)):
                if prices[i] > prices[i-1]:
                    rt += prices[i] - prices[i-1]
            return rt

        dp = [[0 for j in range(len(prices))] for i in range(k+1)]
        for i in range(1,k+1):
            tempMax = -prices[0]
            for j in range(1,len(prices)):
                dp[i][j] = max(dp[i][j-1], prices[j] + tempMax)
                tempMax = max(tempMax, dp[i-1][j-1] - prices[j])
        return dp[k][-1]

s = Solution()
price = [1,3,6,-1,5,9,4]
print(s.maxProfit(2,price))

