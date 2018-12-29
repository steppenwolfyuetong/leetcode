/*
 *  dp[i][j] max coins with nums[i,j]
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0)); 

        for (int len = 1; len <= n; len++) {                                        // calculate sub problems
            for (int start = 0; start + len <= n; start++) {                        // start of range
                int end = start + len - 1;                                          // update dp[start][end]
                for (int finalIndex = start; finalIndex <= end; finalIndex++) {     
                    // shoot at last ballons of finalIndex within range[start][end]
                    // so we need to mutiply nums[start -1] and nums[end + 1]
                    int point = nums[finalIndex];
                    if (start - 1 >= 0) {
                        point *= nums[start - 1];                                   // final
                    }
                    if (end + 1 < n) {
                        point *= nums[end + 1];
                    }

                    if (finalIndex != start) {
                        point += dp[start][finalIndex - 1];
                    }
                    if (finalIndex != end) {
                        point += dp[finalIndex + 1][end];
                    }

                    dp[start][end] = max(dp[start][end], point);
                }
            }
        }
        return dp[0][n-1];
    }
};
