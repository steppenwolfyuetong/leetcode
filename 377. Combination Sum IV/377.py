class Solution(object):
    # dp
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        dp = [0 for i in range(target + 1)]
        dp[0] = 1
        for total in range(1, target + 1):
            for num in nums:
                if total - num >= 0:
                    dp[total] += dp[total - num]
        return dp[target]

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    target = 4
    print(s.combinationSum4(nums,target))
