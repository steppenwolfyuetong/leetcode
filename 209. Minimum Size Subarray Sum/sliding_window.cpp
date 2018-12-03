class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // sliding window [start, end)
        int start = 0, end = 0;

        int result = INT_MAX;
        int curSum = 0;

        while (end < nums.size()) {
            while (end < nums.size() && curSum < s) {
                curSum += nums[end++];
            }

            while (curSum >= s) {
                result = min(end - start, result);
                curSum -= nums[start++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
