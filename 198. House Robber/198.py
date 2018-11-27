class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #dp[i]表示抢劫第i个房子的前提下，最多能获得多少钱
        #动态转移方程为dp[i] = nums[i] + max(dp[:i-1])
        if len(nums) == 0:
            return 0
        curMax = 0
        dp = [0 for i in range(len(nums))]
        for i in range(len(dp)):
            if i > 1:
                curMax = max(curMax,dp[i-2])
            dp[i] = nums[i] + curMax
        return max(dp)

    """
    f(0) = nums[0]
    f(1) = max(num[0], num[1])
    f(k) = max( f(k-2) + nums[k], f(k-1) )
    """
    def rob1(self, nums):
        last, now = 0, 0
        for i in nums:
            last, now = now, max(last + i, now)
        return now

from random import shuffle
s = Solution()
nums = [i for i in range(10)]
shuffle(nums)
s.rob(nums)
