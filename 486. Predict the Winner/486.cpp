#include <vector>
#include <iostream>
using namespace std;

/*
 * 所有分数非负
 * 平分仍算1P获胜
 */

class Solution {
public:
    // dfs
    bool PredictTheWinner(vector<int>& nums) {
        return player1(nums, 0, nums.size() - 1, 0, 0);
    }

    // return true if player1 win
    bool player1(vector<int> &nums, int start, int end, int s1, int s2)
    {
        if(start > end)
        {
            return s1 >= s2;
        }
        return !player2(nums, start + 1, end, s1 + nums[start], s2) || !player2(nums, start, end - 1, s1 + nums[end], s2);
    }

    // return true if player2 win
    bool player2(vector<int> &nums, int start, int end, int s1, int s2)
    {
        if(start > end)
        {
            return s2 > s1;
        }
        return !player1(nums, start + 1, end, s1, s2 + nums[start]) || !player1(nums, start, end - 1, s1, s2 + nums[end]);
    }

    // dp
    bool PredictTheWinner1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));              // use to keep the score gap between player1 and player2

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }

        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j+i < n; j++) 
            {
                dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
            }
        }
        return dp[0][n-1] >= 0;                                 // player1 get more score points than player2
    }
};

int main()
{
    Solution *s = new Solution();
    int array[] = {1,5,3};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s->PredictTheWinner(nums) << endl;
    return 0;
}

