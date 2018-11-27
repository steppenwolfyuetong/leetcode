"""
    有重复数字 与上一题的区别在于start等于mid的情况时需要独立出来
    当没有重复元素时，中间元素与首元素相等，说明此时end = start + 1，即start和end只差1
    而有重复元素时，只能说明start指向元素重复了，start++即可
"""

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = 0
        end = len(nums) - 1
        while start < end and nums[start] >= nums[end]:
            mid = start + (end - start) // 2
            if nums[start] < nums[mid]:
                start = mid + 1
            elif nums[start] == nums[mid]:
                start += 1
            else:
                end = mid
        return nums[start]

s = Solution()
seq = [3,1,1]
print(s.findMin(seq))
seq = [2,2,2,2,2]
print(s.findMin(seq))
seq = [1,2,3,4,5]
print(s.findMin(seq))
seq = [4,5,6,7,1,2,3]
print(s.findMin(seq))
