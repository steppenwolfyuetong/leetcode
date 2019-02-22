#include <vector>
#include <iostream>
using namespace std;

/*
buy[i][j] means the maximum profit with at most i transaction with j prices, which means you have a stock in your hand.
sell[i][j] means the maximum profit with at most i transaction with j prices, which means you don't have a stock in your hand. 

buy[i][j] = max(buy[i][j - 1], sell[i - 1][j - 1] - prices[j]);
sell[i][j] = max(sell[i][j - 1], buy[i][j - 1] + prices[j]);
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) {
            return 0;
        }

        if (k > n / 2) {
            int ans = 0;
            for (int i = 1; i < n; ++i){
                ans += max(prices[i] - prices[i - 1], 0);
            }
            return ans;
        }

        vector<vector<int>> buy(k + 1, vector<int>(n, 0));
        vector<vector<int>> sell(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            buy[i][0] = -prices[0];
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                buy[i][j] = max(buy[i][j - 1], sell[i - 1][j - 1] - prices[j]);
                sell[i][j] = max(sell[i][j - 1], buy[i][j - 1] + prices[j]);
            }
        }
        return sell[k][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> prices = {6,1,3,2,4,7};
    cout << s.maxProfit(2, prices) << endl;
}
