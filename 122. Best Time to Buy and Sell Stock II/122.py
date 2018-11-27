class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        result = 0
        for i in range(1,len(prices)):
            if prices[i] - prices[i-1] > 0:
                result += prices[i] - prices[i-1]
        return result

s = Solution()
print(s.maxProfit([1,2,3,4,5,6]))
