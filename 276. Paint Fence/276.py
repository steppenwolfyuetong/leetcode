"""
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note: n and k are non-negative integers.
"""

"""
最多允许两个相邻柱子为同一颜色
第三根柱子要么根第一个柱子不是一个颜色，要么跟第二根柱子不是一个颜色。
递推式为dp[3] = (k-1) * dp[1] + (k-1) * dp[2]
"""

class Solution():
    def numWays(self, n, k):
        if(n <= 1 or k <= 0)
            return n * k
        dp = [0 for i in range(n+1)]        # dp[i]表示涂完第i个柱子 所有组合的个数
        dp[1] = k
        dp[2] = k * k
        for i in range(3, n+1):
            dp[i] = (k - 1) * (dp[i-1] + dp[i-2])
        return dp[n]


