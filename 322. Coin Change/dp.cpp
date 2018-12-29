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
    /*
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        // dp[i][j] min coins to get j with first i coins
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        // 0 coins to get 0
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 0;
        }

        for (int j = coins[0]; j <= amount; j += coins[0]) {
            dp[0][j] = dp[0][j - coins[0]] + 1;
        }

        for (int i = 1; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                // only use previous coins
                if (dp[i-1][j] != -1) {
                    dp[i][j] = dp[i-1][j];
                }

                // try to use coins[i]
                if (j >= coins[i] && dp[i][j - coins[i]] != -1) {
                    if (dp[i][j] == -1) {
                        dp[i][j] = dp[i][j - coins[i]] + 1;
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
                    }
                }
            }
        }
        return dp[coins.size() - 1][amount];
    }
    */

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        // 可以看到dp[i][j]只依赖于dp[i-1][j]和dp[i][j - coins[i]], 可以降维
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != -1) {
                    if (dp[j] == -1) {
                        dp[j] = dp[j - coins[i]] + 1;
                    } else {
                        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> coins {2,1,5};
    cout << s->coinChange(coins, 11) << endl;

    return 0;
}
