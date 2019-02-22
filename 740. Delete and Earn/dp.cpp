/*
In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

Similar to 198. House Robber, if you earn x, you can't earn x - 1 or x + 1.

Convert origin input to aggregate input. 
[2, 2, 3, 3, 3, 4] -> [2*2, 3*3, 4]

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> reduced(maxEle + 1, 0);
        for (const auto& num : nums) {
            reduced[num] += num;
        }
        return rob1(reduced);
    }

    // O(n) space
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums.front();
        }

        vector<int> dp(n, 0);             // dp[i] is max profix of nums[0,i]
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
    
    // O(1) space
    int rob1(vector<int>& nums) {
        int dp2 = 0;
        int dp1 = 0;

        for (int i = 0; i < nums.size() ; ++i) {
            int dp = max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,2,3,3,3,4};
    cout << s.deleteAndEarn(nums) << endl;
    return 0;
}
