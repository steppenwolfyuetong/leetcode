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
