// dp[i][j] = max profit with i transactions in first j days
//
// dp[i, j] = max(dp[i, j-1], prices[j] - prices[k] + dp[i-1, k]) {0 <= k < j}
//          = max(dp[i, j-1], prices[j] + max(dp[i-1, k] - prices[k]))
// dp[0, j] = 0; 0 transactions makes 0 profit
// dp[i, 0] = 0; if there is only one price data point you can't make any transaction.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        
        if (k >= prices.size() / 2) {
            int result = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    result += prices[i] - prices[i - 1];
                }
            }
            return result;
        }

        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; i++) {
            // assume we buy stock at the first price
            int prevMax = -prices[0];
            for (int j = 1; j < prices.size(); j++) {
                /* dp[i][j] deciding the selling point
                 *  Similar to 0-1 knapsack problem, we have two candidates at here (use or not use):
                 *  1. if we do not use current new available price:
                 *     keep previous max profit dp[i][j-1] at current new available price without doing any new transaction
                 *  2. if we use current new available price:
                 *     throw previous max, update new max profit by doing one more transaction at current new price (bought new stock before, and sell it on current transaction)
                 *  By comparing these two max profit, we will keep the one with max value, and assign to dp[i][j]
                 * */
                dp[i][j] = max(dp[i][j - 1], prices[j] + prevMax);

                /* preMax deciding the buying point
                 *  in order to prepare previous price state for dp[i][j] in next iteration, we need to calculate
                 *  whether we want to use current price as buying price :
                 *  1. if we do not use one more transaction chance to buy new stock, and keep original buying price:
                 *     keep previous max profit, as preMax
                 *  2. if we use one more transaction chance to buy new stock:
                 *     use previous max profit with i - 1 transaction dp[i-1][j] minus new buying price, price[j],
                 *     then we will decide new max profit in next iteration
                 * */
                prevMax = max(prevMax, dp[i - 1][j] - prices[j]);
            }
        }
        
        return dp[k][prices.size() - 1];
    }
};

int main() {
    Solution s;
    vector<int> prices = {6,1,3,2,4,7};
    cout << s.maxProfit(2, prices) << endl;
}
