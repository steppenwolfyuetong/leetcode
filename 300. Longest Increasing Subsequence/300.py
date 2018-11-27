class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)

        rt = 1

        dp = [1 for i in range(len(nums))]              # dp[i]表示以第i个元素为结尾的LIS长度
        for i in range(len(nums)):
            for j in range(i):                          # 遍历第i个之前的所有元素
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
            rt = max(dp[i], rt)
        return rt

"""
O(nlogn) Solution:
http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it == res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
"""

s = Solution()
nums = [10, 9, 2, 5, 3, 7, 101, 18]
print(s.lengthOfLIS(nums))
