class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(auto coin : coins)
        {
            for(int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
            //display(dp);
        }
        return dp[amount];
    }

    /*
     * dp[i][j]: ways to get amount with first i coins
     */
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        if (coins.empty()) {
            return 0;
        }

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];           // only use previous coins
                }
                if (j >= coins[i]) {
                    dp[i][j] += dp[i][j - coins[i]];     // use coins[i]
                }
            }
        }
        return dp[coins.size() - 1][amount];
    }

    void display(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }
};
