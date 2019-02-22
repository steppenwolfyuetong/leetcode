// dp[i][j]: ways to get j with nums[0,i]
//
// dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]
//
// init: dp[i][0] = 0
// result: dp[nums.size() - 1][S]

#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

void display(vector<vector<int>> &dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp.front().size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    // O(n * sum) space
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) {
            return 0;
        }

        // combination of nums can be in range [-sum, sum], in total 2 * sum + 1
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, 0));
        // index of 0 in [-sum, sum] is sum
        int zeroIndex = sum;

        // with first number, only nums[0] and -nums[0]
        dp[0][zeroIndex + nums[0]]++;
        dp[0][zeroIndex - nums[0]]++;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2 * sum + 1; j++) {
                // (j - nums[i] >= 0) && (j + nums[i] < 2 * sum + 1)
                if (j - nums[i] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
                if (j + nums[i] < 2 * sum + 1) {
                    dp[i][j] += dp[i - 1][j + nums[i]];
                }
            }
        }
        return dp[n - 1][zeroIndex + S];
    }

    // dp[i][j] only rely on dp[i - 1][j +/- nums[i]]
    // so we can use only O(sum) space
    int findTargetSumWays(vector<int>& nums, int S) {
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{1,1,1,1,1};
    /*
    cout << s->findTargetSumWays(nums, 1) << endl;
    cout << s->findTargetSumWays(nums, 2) << endl;
    cout << s->findTargetSumWays(nums, 3) << endl;
    cout << s->findTargetSumWays(nums, 4) << endl;
    cout << s->findTargetSumWays(nums, 5) << endl;
    */

    nums = {0,0,0,0,0,0,0,0,1};
    cout << s->findTargetSumWays(nums, 1) << endl;
    return 0;
}
