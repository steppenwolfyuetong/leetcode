class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        index = 0                   # 下一个可填充的位置
        for num in nums:
            if num != 0:            # 找到不为0的数
                nums[index] = num
                index += 1
        for i in range(index, len(nums)):           # 剩下的位置均填0
            nums[i] = 0

s = Solution()
nums = [0,1,0,3,12]
s.moveZeroes(nums)
print(nums)
