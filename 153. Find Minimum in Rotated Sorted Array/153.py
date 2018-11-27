"""
    没有重复数字
    二分搜索，首先分为两种情况：
    (1)start <= end:也就是搜索部分是排序好的
       显然start为最小值 返回结果
    (2)start > end:搜索部分是旋转过的，也是分为两种情况：
        1)start < mid,即翻转处在mid的右侧，
            start = mid + 1
        2)start > mid,即翻转处在mid的左侧，
          不过有一种特殊情况，此时mid就是最小值，因此
            end = mid
"""


class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = 0
        end = len(nums) - 1
        while nums[start] > nums[end]:
            mid = start + (end - start) // 2
            if nums[start] > nums[mid]:
                end = mid
            else:
                start = mid + 1
        return nums[start]

s = Solution()
nums = [i for i in range(9)]
for i in range(9):
    seq = nums[i:] + nums[:i]
    print(s.findMin(seq))

