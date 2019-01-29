// dp[i]: max sub array sum ending with nums[i]

class Solution {
public:
    // O(n) space
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }

    // O(1) space
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }

        int result = nums[0], cur = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            result = max(cur, result);
        }
        return result;
    }
};
