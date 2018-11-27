class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        rt = 0
        count = 0
        for num in nums:
            if count == 0:
                rt = num
                count = 1
            else:
                if num == rt:
                    count += 1
                else:
                    count -=1
        return rt

    # 基于快速排序思想的方法
    def majorityElement1(self, nums):
        low = 0
        high = len(nums) - 1
        middle = low + (high - low) >> 1
        index = self.partition(nums, low, high)
        while index != middle:
            if index > middle:
                high = index - 1
                index = self.partition(nums, low, high)
            else:
                low = index + 1
                index = self.partition(nums, low, high)
        return nums[middle]

    def partition(self, nums, start, end):
        pivot = nums[start]
        while start < end:
            while start < end and nums[end] >= pivot:
                end -=1
            nums[start] = nums[end]
            while start < end and nums[start] <= pivot:
                start +=1
            nums[end] = nums[start]
        nums[start] = pivot
        return start

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,2,2,2,5,4,2]
    print(s.majorityElement(nums))
    print(s.majorityElement1(nums))
