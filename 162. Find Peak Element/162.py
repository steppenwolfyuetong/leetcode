"""
由于Peak一定比两侧的元素大
那么当从左向右遍历时 第一个比右侧元素大的元素一定就是Peak
而从右向左遍历时 第一个比左侧元素大的元素一定就是Peak
"""

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start, end = 0, len(nums) - 1
        while start < end:
            mid = (start + end) // 2
            if nums[mid] > nums[mid+1]:
                end = mid           #从右向左
            else:
                start = mid + 1     #从左向右
        return start

s = Solution()
nums = [1,2,4,1]
print(s.findPeakElement(nums))


