"""
不需要刚好到数组最后 只用超过即可 用right_most保存能走到的最右
向后遍历数组
不断更新right_most即可

也可以向前遍历 用left_most保存当前能走到的最左处
看是否能到最左测
"""

class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        right_most = 0
        i = 0
        while(i <= right_most and right_most < len(nums) - 1):
            right_most = max(right_most, nums[i] + i)
            i += 1
        return right_most >= len(nums) - 1

s = Solution()
print(s.canJump([2,3,1,1,4]))
print(s.canJump([3,2,1,0,4]))
