class Solution:
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # 1 <= k <= n <= 30,000.
        s = sum(nums[:k])
        rt = s
        for i in range(k, len(nums)):
            s += nums[i] - nums[i - k]
            rt = max(rt, s)
        return rt / k

if __name__ == "__main__":
    s = Solution()
    nums = [1,12,-5,-6,50,3]
    k = 4
    print(s.findMaxAverage(nums, k))



