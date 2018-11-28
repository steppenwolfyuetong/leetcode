#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 2) {
            return 0;
        }
        vector<int> dp(cost.size() + 1, 0);        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= dp.size(); i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return dp[cost.size()];
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> xxx = vector<int>{0,0,0,2};
    cout << s->minCostClimbingStairs(xxx) << endl;
    return 0;
}
