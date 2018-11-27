class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        table = set()
        for num in nums:
            if num not in table:
                table.add(num)
            else:
                return True
        return False

s = Solution()
print(s.containsDuplicate([1,2,3,4]))
print(s.containsDuplicate([1,2,3,2,1]))
