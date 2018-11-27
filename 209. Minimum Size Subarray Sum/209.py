class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        # O(n) 两个指针维护
        if(sum(nums) < s):
            return 0
        n = len(nums)
        start = 0
        curSum = 0
        minLen = n
        for i in range(n):
            curSum += nums[i]
            while curSum >= s:
                minLen = min(minLen, i - start + 1)
                curSum -= nums[start]
                start += 1
        return minLen

s = Solution()
target = 7
nums = [2,3,1,2,4,3]
print(s.minSubArrayLen(7, nums))
