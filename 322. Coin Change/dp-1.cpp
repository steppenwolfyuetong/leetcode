// dp[i][j] min coins to make up j amount with first i types of coins
//
//
// dp[i][j] = min(dp[i][j], min(dp[i - 1][j - k * coin[i]] + k))
// 即如果能通过i种硬币达到j, 可以通过i-1种硬币和k个第i种硬币达到j, 比较即可
// 需要遍历i, j, k

#include <vector>
#include <iostream>
using namespace std;

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
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));

        dp[0][0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 0;
        }

        for (int j = coins[0]; j <= amount; j += coins[0]) {
            dp[0][j] = dp[0][j - coins[0]] + 1;
        }

        for (int i = 1; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; j - k * coins[i] >= 0; k++) {
                    if (dp[i - 1][j - k * coins[i]] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - k * coins[i]] + k);
                    }
                }
            }
        }

        return dp[coins.size() - 1][amount] == INT_MAX ? -1 : dp[coins.size() - 1][amount];
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> coins;
    coins = {1,2,5};
    cout << s->coinChange(coins, 11) << endl;

    return 0;
}
