class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        xor = 0
        for i in range(len(nums)):
            xor ^= i
            xor ^= nums[i]
        return xor ^ len(nums)

"""
另一种方法 对数组求和 与从0-n的和相比 求出缺少的数
"""

s = Solution()
nums = [0,1,3]
print(s.missingNumber(nums))
