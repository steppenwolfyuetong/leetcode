# 定义状态dp[i]为以第i个数为结尾的最大的和
# 状态转移方程dp[i] = max(nums[i],dp[i-1]+nums[i])

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxSubArray(self, nums):
        if len(nums) == 1:
            return nums[0]
        dp = [nums[0]] + [0] * (len(nums)-1)
        for i in range(1,len(nums)):
            dp[i] = max(nums[i],dp[i-1]+nums[i])
        return max(dp)

print(Solution.maxSubArray(Solution.maxSubArray,[-2,-1]))