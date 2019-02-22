/*
 * buy[i]   max profit ends with buy
 * sell[i]  max profit ends with sell
 * rest[i]  max profit ends with reset
 *
 *
 * buy[i + 1] = max(rest[i] - price[i + 1], buy[i])         // must rest before buy
 * sell[i + 1] = max(buy[i] + price[i + 1], sell[i])        // must buy before sell
 * rest[i + 1] = max(buy[i], sell[i], rest[i])
 *
 * since buy[i] <= rest[i] and rest[i] <= sell[i],
 * rest[i + 1] = sell[i]
 *
 * which leads to following (substitute rest with sell):
 * buy[i + 1] = max(sell[i - 1] - price[i + 1], buy[i])
 * sell[i + 1] = max(buy[i] + price[i + 1], sell[i])
 *
 * so max profit of ith day is consist of i - 1 and i - 2
 *
 * Let b2, b1, b0 represent buy[i - 2], buy[i - 1], buy[i] 
 * Let s2, s1, s0 represent sell[i - 2], sell[i - 1], sell[i]
 *
 * b0 = Math.max(b1, s2 - prices[i]); 
 * s0 = Math.max(s1, b1 + prices[i]);
 *
 * First we define the initial states at i = 0:
 * We can buy. The max profit at i = 0 ending with a buy is -prices[0].
 * We cannot sell. The max profit at i = 0 ending with a sell is 0.
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int n = prices.size();
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = -prices[0]; 
        buy[1] = -min(prices[0], prices[1]);
        sell[1] = max(prices[1] - prices[0], 0);

        for (int i = 2; i < n; i++) {      
            // must buy after reset, so if want to buy on day, need to sell on day (i - 2)
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[n - 1];
    }

    // O(1)
    /*
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int b0 = -prices[0], b1 = b0;
        int s0 = 0, s1 = 0, s2 = 0;

        for(int i = 1; i < prices.size(); i++) {
            b0 = max(b1, s2 - prices[i]);
            s0 = max(s1, b1 + prices[i]);
            b1 = b0; s2 = s1; s1 = s0;
        }
        return s0;
    }
    */
};

int main() {
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout << s.maxProfit(prices) << endl;
}
