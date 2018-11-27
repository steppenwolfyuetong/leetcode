class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 可以将问题转化为两个问题
        """
        Suppose there are n houses, since house 0 and n - 1 are now neighbors,
        we cannot rob them together and thus the solution is now the maximum of
            * Rob houses 0 to n - 2;
            * Rob houses 1 to n - 1.
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        else:
            return max(self.robOriginal(nums[:-1]),self.robOriginal(nums[1:]))

    # House Robber
    def robOriginal(self, nums):
        rob = 0     # max money if rob previous house
        notrob = 0  # max money if not rob previous house
        for i in range(len(nums)):
            currob = notrob + nums[i]       # 要抢当前房子 必须不能抢前一个房子
            notrob = max(notrob, rob)       # 不抢当前房子 更新notrob
            rob = currob
        return max(rob,notrob)

s = Solution()
nums = [0,8,2,4,1,3,6,9,7,5]
print(s.robOriginal(nums))

