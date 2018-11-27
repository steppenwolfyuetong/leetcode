class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        table = {}
        for i in range(len(nums)):
            if nums[i] not in table:
                table[nums[i]] = i
            else:
                if i - table[nums[i]] <= k:
                    return True
                else:
                    table[nums[i]] = i
        return False

s = Solution()
nums = [2,4,6,8,6,4,2]
print(s.containsNearbyDuplicate(nums,2))
