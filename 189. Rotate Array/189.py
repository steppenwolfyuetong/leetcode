"""
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
"""
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n == 0 or k <= 0:
            return
        copy = nums[:]
        for i in range(n):
            nums[(i + k) % n] = copy[i]

    def rotate1(self, nums, k):
        # Reverse the first n - k elements, the last k elements,
        # and then all the n elements.
        # 由于python的切片不是引用
        n = len(nums)
        k = k % n
        self.reverse(nums,0,n-k-1)
        self.reverse(nums,n-k,n-1)
        self.reverse(nums,0,n-1)

    def reverse(self,nums,left,right):
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1


s = Solution()
array = [i for i in range(1,8)]
s.rotate(array,3)
print(array)

array = [i for i in range(1,7)]
s.rotate1(array,11)
print(array)
