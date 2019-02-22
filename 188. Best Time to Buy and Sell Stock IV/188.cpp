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
            for (int j = 1; j < prices.size(); j++) {
                dp[i][j] = dp[i][j - 1];
                for (int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + prices[j] - prices[k]);
                }
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
