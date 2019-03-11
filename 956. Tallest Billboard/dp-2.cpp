/*
Consider this problem as:
Given a list of numbers, multiply each number with 1 or 0 or -1, make the sum of all numbers to 0. 
Find a combination which has the largest sum of all positive numbers.
e.g. Given [1,2,3,4,5,6], we have 1 * 0 + 2 + 3 - 4 + 5 - 6 = 0, the sum of all positive numbers is 2 + 3 + 5 = 10. The answer is 10.

This is a knapsack problem. Similar to 494. Target Sum (see 494/dp-1.cpp) and 416. Partition Equal Subset Sum.
*/

/*
similar to dp-1.cpp
dp[i][j] denotes the **largest positive sum** at the case of after using i-th rod 
and the difference between positive and negative rods is j - sum of all rods.

Then dp[i][j] = max(dp[i - 1][j - rods[i - 1]] + rods[i - 1],
                    dp[i - 1][j + rods[i - 1]],
                    dp[i - 1][j]) 

result: height[n][sum]
*/

#include "../leetcode.h"

class Solution {
public:
    // O(n * sum) space
    /*
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int zeroIndex = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * zeroIndex + 1, -1));
        
        dp[0][zeroIndex] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2 * zeroIndex + 1; j++) {
                // add to rods[i - 1] to positive group
                if (j - rods[i - 1] >= 0 && dp[i - 1][j - rods[i - 1]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - rods[i - 1]] + rods[i - 1]);
                }
                // add to rods[i - 1] to negative group
                if (j + rods[i - 1] < 2 * zeroIndex + 1 && dp[i - 1][j + rods[i - 1]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + rods[i - 1]]);
                }
                // don't select rods[i - 1]
                if (dp[i - 1][j] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
            }
        }
        return dp[n][zeroIndex];
    }
    */

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int zeroIndex = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(2 * zeroIndex + 1, -1);
        
        dp[zeroIndex] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp(dp);
            for (int j = 0; j < 2 * zeroIndex + 1; j++) {
                // add to rods[i] to positive group
                if (j - rods[i] >= 0 && dp[j - rods[i]] != -1) {
                    temp[j] = max(temp[j], dp[j - rods[i]] + rods[i]);
                }
                // add to rods[i] to negative group
                if (j + rods[i] < 2 * zeroIndex + 1 && dp[j + rods[i]] != -1) {
                    temp[j] = max(temp[j], dp[j + rods[i]]);
                }
                // don't select rods[i]
                if (dp[j] != -1) {
                    temp[j] = max(temp[j], dp[j]);
                }
            }
            swap(dp, temp);
        }
        return dp[zeroIndex];
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
