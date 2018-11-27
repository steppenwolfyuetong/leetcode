class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 1
        high = len(nums) - 1        # high = n

        while low < high:
            mid = (low + high) // 2
            count = 0
            for num in nums:
                if num <= mid:
                    count += 1
            if count <= mid:
                low = mid + 1
            else:
                high = mid
        return low

s = Solution()
nums = [1,3,2,1,4,5,6,7]
print(s.findDuplicate(nums))
