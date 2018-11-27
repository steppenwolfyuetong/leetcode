class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [-1 for i in range(amount + 1)]
        dp[0] = 0
        for i in range(1, amount + 1):
            for c in coins:
                if i >= c and dp[i-c] != -1:
                    if dp[i] == -1:
                        dp[i] = dp[i-c] + 1
                    else:
                        dp[i] = min(dp[i], dp[i-c] + 1)
        return dp[-1]

if __name__ == "__main__":
    s = Solution()
    coins = [176,6,366,357,484,226,1,104,160,331]
    amount = 5557
    print(s.coinChange(coins, amount))
