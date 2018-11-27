"""
Given numbers [2, 3, 4, 5], regarding the third number 4, the product of array except 4 is 2*3*5 which consists of two parts:
left 2*3 and right 5. The product is left*right. We can get lefts and rights:
Numbers:     2    3    4     5
Lefts:            2  2*3 2*3*4
Rights:  3*4*5  4*5    5
"""

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        rt = [1 for i in range(n)]

        # 计算当前数的左边的乘积
        for i in range(1,n):
            rt[i] = rt[i-1] * nums[i-1]

        right = 1
        # 计算当前数的右边的乘积 并和之前的结果相乘
        for i in range(n-1,-1,-1):
            rt[i] *= right
            right *= nums[i]
        return rt

s = Solution()
print(s.productExceptSelf([1,2,3,4]))
print(s.productExceptSelf([2,3,4,5]))


