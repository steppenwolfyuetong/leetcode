"""
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target
Let P be the positive subset and N be the negative subset

Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is +1-2+3-4+5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

    * sum(P) - sum(N) = target
    * sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N)
    * 2 * sum(P) = target + sum(nums)

So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

PS: (target + sum(nums)) must be even

Refer to problem 416.Partition Equal Subset Sum
"""

class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        if sum(nums) < S or (S + sum(nums)) % 2:
            return 0
        else:
            return self.subsetSum(nums, (S + sum(nums)) // 2)

    def subsetSum(self, nums, target):
        # dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
        dp = [0 for i in range(target + 1)]
        dp[0] = 1
        for num in nums:
            for tar in range(target, num - 1, -1):
                dp[tar] += dp[tar - num]
        return dp[target]

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,1,1,1]
    target = 3
    print(s.findTargetSumWays(nums, target))
