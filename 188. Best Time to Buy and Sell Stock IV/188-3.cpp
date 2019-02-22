#include <vector>
#include <iostream>
using namespace std;

/*
buy[i][j] means the maximum profit with at most i transaction with j prices, which means you have a stock in your hand.
sell[i][j] means the maximum profit with at most i transaction with j prices, which means you don't have a stock in your hand. 

buy[i][j] = max(buy[i][j - 1], sell[i - 1][j - 1] - prices[j]);
sell[i][j] = max(sell[i][j - 1], buy[i][j - 1] + prices[j]);

O(kn) space, we can use only O(k) space only
buy[i] = max(buy[i], sell[i - 1] - prices[j]);
sell[i] = max(sell[i], buy[i] + prices[j]);
 */

// to hard
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

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);

        buy[0] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k - 1];
    }
};

int main() {
    Solution s;
    vector<int> prices;
    prices = {6,1,3,2,4,7};
    cout << s.maxProfit(2, prices) << endl;
    prices = {1,2};
    cout << s.maxProfit(1, prices) << endl;
    prices = {3,2,6,5,0,3};
    cout << s.maxProfit(2, prices) << endl;
}
