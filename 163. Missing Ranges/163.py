class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        rt = []
        if len(nums) == 0:
            return rt
        #相当于lower是missing range的最小值 不断增大lower
        for i in range(len(nums)):
            if lower == nums[i]:
                lower += 1
            if lower < nums[i]:
                rng = str(lower)
                if lower < nums[i] - 1:
                    rng += "->" + str(nums[i] - 1)
                rt.append(rng)
                lower = nums[i] + 1

        if lower < upper:
            rng = str(lower)
            if lower < upper - 1:
                rng += "->" + str(upper)
            rt.append(rng)

        print(rt)
        return rt

s = Solution()
nums = [0, 1, 3, 50, 75]
s.findMissingRanges(nums,0,99)

