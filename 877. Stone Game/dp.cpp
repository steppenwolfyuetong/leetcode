#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // common approach
    // dp[i][j] means the biggest number of stones you can get more than opponent picking piles in piles[i] ~ piles[j].
    //
    // i <= j
    //
    // dp[i][i] = piles[i]
    //
    //
    // pick[i]: dp[i][j] = piles[i] - dp[i+1][j]
    // pick[j]: dp[i][j] = piles[j] - dp[i][j-1]
    //
    // dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};

/*
Alex is first to pick pile.
piles.length is even, and this lead to an interesting fact:
Alex can always pick odd piles or always pick even piles!

For example,
If Alex wants to pick even indexed piles piles[0], piles[2], ....., piles[n-2],
he picks first piles[0], then Lee can pick either piles[1] or piles[n - 1].
Every turn, Alex can always pick even indexed piles and Lee can only pick odd indexed piles.

In the description, we know that sum(piles) is odd.
If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.

So, Alex always defeats Lee in this game.
*/

int main() {
    Solution *s = new Solution();
    vector<int> piles{5,3,4,5};
    cout << s->stoneGame(piles) << endl;
    return 0;
}
