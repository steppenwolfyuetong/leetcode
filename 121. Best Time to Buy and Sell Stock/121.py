class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        if len(prices) < 2:
            return 0
        result = 0
        cur_min = prices[0]
        for i in range(1,len(prices)):
            result = max(result, prices[i] - cur_min)
            cur_min = min(cur_min, prices[i])
        return result

s = Solution()
print(s.maxProfit([2,4,1,4,3,5]))
