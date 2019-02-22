/*
 *  buy[i]   max profit ends with buy   (ends with buy is ok, may not buy on day i)
 *  sell[i]  max profit ends with sell  (ends with sell if ok, may not sell on day i)
 *
 *  buy[0]  = -prices[0]
 *  sell[0] =  0
 *
 *  At day i, we may buy stock (from previous sell status) or do nothing (from previous buy status):
 *  buy[i]  = max(sell[i - 1] - prices[i], buy[i-1])        // must sell before buy
 *  At day i, we may sell stock (from previous buy status) or keep holding (from previous sell status):
 *  sell[i] = max(buy[i - 1] + prices[i] - fee, sell[i-1])        // must sell after buy
 *
 *
 *  b1 = max(s0 - p[i], b0)
 *  s1 = max(b0 + p[i], s0)
 */



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int b0 = -prices[0], s0 = 0;            // initial state
        int b1 = 0, s1 = 0;

        for (int i = 1; i < prices.size(); i++) {
            b1 = max(s0 - prices[i], b0);
            s1 = max(b0 + prices[i] - fee, s0);     // pay the fee when sell
            b0 = b1;
            s0 = s1;
        }

        return s1;
    }
};
