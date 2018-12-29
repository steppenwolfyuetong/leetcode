/*
The recursive solution is very slow, because its runtime is exponential

The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset
For example:
Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is +1-2+3-4+5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

Then let's see how this can be converted to a subset sum problem:

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)

So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Note that the above formula has proved that target + sum(nums) must be even
We can use that fact to quickly identify inputs that do not have a solution (Thanks to @BrunoDeNadaiSarnaglia for the suggestion)
For detailed explanation on how to solve subset sum problem, you may refer to 416. Partition Equal Subset Sum
*/

#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) {                      // avoid MLE if S is huge and sum is small
            return 0;
        }

        int target = sum + S;
        if (target & 1)
            return 0;
        target >>= 1;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto& num : nums) {
            // need to use dp[i - num], so need iterate in reverse
            for (int i = target; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{1,1,1,1,1};
    cout << s->findTargetSumWays(nums, 3) << endl;
    return 0;
}
