"""
dp
f[i]表示从nums[0]出发 走到nums[i]时 还能走的最大步数
f[i] = max(f[i-1],a[i-1]) - 1
"""
class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        f = [0 for i in range(len(nums))]
        for i in range(1,len(nums)):
            f[i] = max(f[i-1], nums[i-1]) - 1
            if f[i] < 0:
                return False
        return f[-1] >= 0

s = Solution()
print(s.canJump([2,3,1,1,4]))
print(s.canJump([3,2,1,0,4]))
