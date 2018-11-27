class Solution(object):
    # dp
    """
    dp1 is the length of a longest wiggle subsequence of {nums[0],...,nums[i]}, with a positive difference between its last two numbers.
    dp2 is the length of a longest wiggle subsequence of {nums[0],...,nums[i]}, with a nagative difference between its last two numbers.
    """
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        size = len(nums)
        if size == 0:
            return 0

        dp1 = [1 for i in range(size)]
        dp2 = [1 for i in range(size)]

        for i in range(1, size):
            if nums[i] > nums[i-1]:
                dp1[i] = dp2[i-1] + 1
                dp2[i] = dp2[i-1]
            elif nums[i] < nums[i-1]:
                dp2[i] = dp1[i-1] + 1
                dp1[i] = dp1[i-1]
            else:
                dp1[i] = dp1[i-1]
                dp2[i] = dp2[i-1]
        return max(dp1[-1], dp2[-1])

    # Also DP: save space by not using the whole array, but only the last elements.
    def wiggleMaxLength1(self, nums):
        pos, neg = 1, 1
        if len(nums) == 0:
            return 0
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                pos = neg + 1
            elif nums[i] < nums[i-1]:
                neg = pos + 1
        return max(pos, neg)

if __name__ == "__main__":
    s = Solution()
    nums = [1,17,5,10,13,15,10,5,16,8]
    print(s.wiggleMaxLength(nums))
    print(s.wiggleMaxLength1(nums))
