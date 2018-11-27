class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0

        rt, cnt = 0, 0
        for i in range(len(nums)):
            if i == 0 or nums[i-1] < nums[i]:
                cnt += 1
                rt = max(rt, cnt)
            else:
                cnt = 1
        return rt

"""
class Solution(object):
    def findLengthOfLCIS(self, nums):
        ans = anchor = 0
        for i in range(len(nums)):
            if i and nums[i-1] >= nums[i]: anchor = i
            ans = max(ans, i - anchor + 1)
        return ans
"""
