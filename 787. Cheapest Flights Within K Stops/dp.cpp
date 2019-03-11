// dp[i][j]: minimun cost from src to city j with exactly i steps
//
// dp[i][j] = min(dp[i][j], dp[i - 1][u] + cost[u][j])
//           (u is the city which have flight from u to j with cost[u][j])
//
// result: dp[K + 1][dst]

#include "../leetcode.h"

void display(vector<vector<int>> &dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp.front().size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    // O(nk) space
    /*
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        constexpr int kInfCost = 1e9;
        // we can stop K times, so we can take at most K + 1 flights
        // and because we will add cost to dp, we can not set initial value to INT_MAX
        vector<vector<int>> dp(K + 2, vector<int>(n, kInfCost));
        // we can get to src with no flights
        for (int k = 0; k <= K + 1 ; k++) {
            dp[k][src] = 0;
        }

        for (int k = 1; k <= K + 1; k++) {
            for (const auto& fly : flights) {
                dp[k][fly[1]] = min(dp[k][fly[1]], dp[k-1][fly[0]] + fly[2]);
            }
        }

        return dp[K + 1][dst] == kInfCost ? -1 : dp[K + 1][dst];
    }
    */

    // O(n) space is enough
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        constexpr int kInfCost = 1e9;
        // we can stop K times, so we can take at most K + 1 flights
        // and because we will add cost to dp, we can not set initial value to INT_MAX
        vector<int> dp(n, kInfCost);
        dp[src] = 0;

        for (int k = 1; k <= K + 1; k++) {
            vector<int> tmp(dp);
            for (const auto& fly : flights) {
                tmp[fly[1]] = min(tmp[fly[1]], dp[fly[0]] + fly[2]);
            }
            swap(dp, tmp);
        }

        return dp[dst] == kInfCost ? -1 : dp[dst];
    }
};

int main() {
    Solution s;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << s.findCheapestPrice(3, flights, 0, 2, 0) << endl;
    cout << s.findCheapestPrice(3, flights, 0, 2, 1) << endl;
}
