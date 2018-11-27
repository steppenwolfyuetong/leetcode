class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        """
        利用快排的思想，在快速排序中，如果枢轴在第k个位置，则前面的元素都比
        枢轴小，后面的元素都比枢轴大，即枢轴为第k小的元素，直接用快排的partition即可
        1. Initialize left to be 0 and right to be nums.size() - 1;
        2. Partition the array, if the pivot is at the k-1-th position, return it (we are done);
        3. If the pivot is right to the k-1-th position, update right to be the left neighbor of the pivot;
        4. Else update left to be the right neighbor of the pivot.
        5. Repeat 2.
        """
        k = len(nums) - k           #第k大元素的索引为len(nums) - k
        low = 0
        high = len(nums) - 1
        while low < high:
            index = self.partition1(nums, low, high)
            if index < k:
                low = index + 1
            elif index > k:
                high = index - 1
            else:
                break
        return nums[k]

#-----------------------------------------------------------------
#快速排序
#-----------------------------------------------------------------
    def quickSort1(self, nums, left, right):
        if left >= right:
            return

        pivot = nums[left]
        low = left
        high = right
        while low < high:
            while low < high and nums[high] > pivot:
                high -= 1
            nums[low] = nums[high]
            while low < high and nums[low] < pivot:
                low += 1
            nums[high] = nums[low]
        nums[low] = pivot
        self.quickSort1(nums, left, low - 1)
        self.quickSort1(nums, low + 1, right)

    # x x x x x x | x x x x x | x x x x x
    # 小于pivot   | 未知      | 大于pivot
    # 双向扫描
    def partition1(self, nums, left, right):
        pivot = nums[left]
        while left < right:
            while left < right and nums[right] >= pivot:
                right -= 1
            nums[left] = nums[right]
            while left < right and nums[left] <= pivot:
                left += 1
            nums[right] = nums[left]
        nums[left] = pivot
        return left

    # x x x x x x | x x x x x | x x x x x
    # 小于pivot   | 大于pivot | 未知
    # 单向扫描
    def partition2(self, nums, left, right):
        pivot = nums[right]
        index = left            #index之前的数都比pivot小
        for i in range(left,right):
            if nums[i] < pivot:
                nums[i], nums[index] = nums[index], nums[i]
                index += 1
        nums[index], nums[right] = nums[right], nums[index]
        return index

    def quickSort2(self, nums, low, high):
        if low >= high:
            return
        index = self.partition1(nums, low, high)
        # index = self.partition2(nums, low, high)
        self.quickSort2(nums, low, index - 1)
        self.quickSort2(nums, index + 1, high)

from random import shuffle
s = Solution()
nums = [i for i in range(10)]
shuffle(nums)
s.quickSort1(nums, 0, len(nums) - 1)
print(nums)
shuffle(nums)
s.quickSort2(nums, 0, len(nums) - 1)
print(nums)
shuffle(nums)
print(s.findKthLargest(nums,5))
