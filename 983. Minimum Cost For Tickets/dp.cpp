/*
dp[i]: min cost to travel i days

dp[i] = min(dp[i-1] + costs[0], dp[i-7] + costs[1], dp[i-30] + costs[2])

init state:
dp[0] = 0
dp[i] = dp[i-1] (if no travels on day i)
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = 365;
        vector<int> dp(n + 1, 0);
        unordered_set<int> travel(days.begin(), days.end());

        for (int i = 1; i <= n; i++) {
            if (travel.find(i) == travel.end()) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[n];
    }
};
