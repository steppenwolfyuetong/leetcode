class Solution:
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        """
        len[k] is the length of longest subsequence ending with nums[k];
        cnt[k] is total number of longest subsequence ending with nums[k];

        len[k] = max(len[k], len[i] + 1) for all i <= k and nums[i] < nums[k]
        cnt[k] = sum(cnt[i]) for all i <= k and nums[i] < nums[k] and len[i] = len[k] - 1
        """



        dpLen = [1 for i in range(len(nums))]
        dpCnt = [1 for i in range(len(nums))]
        maxLen, rt = 1, 0
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dpLen[i] < dpLen[j] + 1:
                        dpLen[i] = dpLen[j] + 1
                        dpCnt[i] = dpCnt[j]
                    elif dpLen[i] == dpLen[j] + 1:
                        dpCnt[i] += dpCnt[j]
            maxLen = max(maxLen, dpLen[i])

        for i in range(len(nums)):
            if dpLen[i] == maxLen:
                rt += dpCnt[i]
        return rt

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,5,4,7]
    print(s.findNumberOfLIS(nums))
    nums = [2,2,2,2,2]
    print(s.findNumberOfLIS(nums))

