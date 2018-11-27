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

    void display(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }
};
