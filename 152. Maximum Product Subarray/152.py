# 定义状态dp[i]为以第i个数为结尾的最大的乘积
# a[i]保存以i为结尾的最大的乘积
# b[i]保存以i为结尾的最小的乘积
# a[i] = max(a[i-1] * num[i], b[i-1] * num[i], num[i])
# b[i] = min(a[i-1] * num[i], b[i-1] * num[i], num[i])

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxProduct(self, nums):
        if len(nums) == 1:
            return nums[0]
        a = [nums[0]]
        b = [nums[0]]
        for i in range(1,len(nums)):
            a.append(max(a[i-1] * nums[i] , b[i-1] * nums[i] , nums[i]))
            b.append(min(a[i-1] * nums[i] , b[i-1] * nums[i] , nums[i]))
        return max(a)

print(Solution.maxProduct(Solution.maxProduct,[2,3,-2,-6,4,3,2,-4]))