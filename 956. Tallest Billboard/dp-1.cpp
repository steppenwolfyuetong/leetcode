/*
Consider this problem as:
Given a list of numbers, multiply each number with 1 or 0 or -1, make the sum of all numbers to 0. 
Find a combination which has the largest sum of all positive numbers.
e.g. Given [1,2,3,4,5,6], we have 1 * 0 + 2 + 3 - 4 + 5 - 6 = 0, the sum of all positive numbers is 2 + 3 + 5 = 10. The answer is 10.

This is a knapsack problem. Similar to 494. Target Sum (see 494/dp-1.cpp) and 416. Partition Equal Subset Sum.
*/

/*
dp[i][j] represents whether the sum of first i numbers can be (j - sum). dp[0][sum] = true.

Then dp[i][j] = dp[i - 1][j - rods[i - 1]] | dp[i - 1][j + rods[i - 1]] | dp[i - 1][j].
height[i][j] represents the largest sum of all positive numbers when the sum of first i numbers is (j - sum).

result: height[n][sum]
*/

#include "../leetcode.h"

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int zeroIndex = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(2 * zeroIndex + 1, false));
        vector<vector<int>> height(n + 1, vector<int>(2 * zeroIndex + 1, 0));
        
        dp[0][zeroIndex] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2 * zeroIndex + 1; j++) {
                // add to rods[i - 1] to positive group
                if (j - rods[i - 1] >= 0 && dp[i - 1][j - rods[i - 1]]) {
                    dp[i][j] = true;
                    height[i][j] = max(height[i][j], height[i - 1][j - rods[i - 1]] + rods[i - 1]);
                }
                // add to rods[i - 1] to negative group
                if (j + rods[i - 1] < 2 * zeroIndex + 1 && dp[i - 1][j + rods[i - 1]]) {
                    dp[i][j] = true;
                    height[i][j] = max(height[i][j], height[i - 1][j + rods[i - 1]]);
                }
                // don't select rods[i - 1]
                if (dp[i - 1][j]) {
                    dp[i][j] = true;
                    height[i][j] = max(height[i][j], height[i - 1][j]);
                }
            }
        }
        return height[n][zeroIndex];
    }
};

int main() {
    Solution s;
    vector<int> rods;
    rods = {1,2,3,4,5,6};
    cout << s.tallestBillboard(rods) << endl;
    rods = {1,2,3,6};
    cout << s.tallestBillboard(rods) << endl;
    rods = {1,2};
    cout << s.tallestBillboard(rods) << endl;
}
