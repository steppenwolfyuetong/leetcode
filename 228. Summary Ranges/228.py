class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        rt = []
        if not nums:
            return rt
        i = 0
        cur = nums[i]
        while i < len(nums):
            cur = nums[i]
            lower = cur
            rng = str(cur)
            i += 1
            cur += 1
            while i < len(nums) and cur == nums[i]:
                i += 1
                cur += 1
            if lower != cur - 1:
                rng += "->" + str(cur - 1)
            rt.append(rng)
        return rt

s = Solution()
print(s.summaryRanges([0,1,2,4,5,7]))
print(s.summaryRanges([0,2]))
