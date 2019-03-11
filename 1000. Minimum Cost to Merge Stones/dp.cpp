class Solution {
public:
    /*
     *  A move consists of merging exactly K consecutive piles into one pile.
     *
     *  1. only can merge into one pile when (n - 1) % (K - 1) == 0, there are (n - 1) / (K - 1) merges
     *  2. if we try to merge n stones, remaining stones are (n - 1) % (K - 1) + 1
     *  3. when [i, j] can merge into one pile, last time merge cost is sum(stones[i, j])
     *
     *  dp[i][j][k] = cost for merge [i, j] into k piles
     *
     *  dp[i][j][k] = min( (dp[i][m][1] + dp[m + 1][j][k-1]) for m in range [i, j) )
     *                k >= 2
     *
     *  and dp[i][j][1] = dp[i][j][K] + sum(stones[i, j]) if merge stones[i, j] into K piles is possible
     *
     *  so we have to solve sub problem of shorter length, and iterate k from 2 to K
     *
     *  init: dp[i][i][1] = 0, length = 1
     *  result: dp[0][n-1][1]
     */
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) {
            return -1;
        }
        
        vector<int> prefixSum(n + 1);           // build prefix sum so we can get sum(stones(i, j))
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stones[i];
            prefixSum[i + 1] = sum;
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, INT_MAX)));
        for (int i = 0; i < n; i++) {
            dp[i][i][1] = 0;
        }
        
        for (int len = 2; len <= n; len++) {                // sub problem for shorter length
            for (int i = 0; i <= n - len; i++) {            // start
                int j = i + len - 1;                        // end
                for (int k = 2; k <= K; k++) {              // k piles
                    for (int m = i; m < j; m += K - 1) {    // break point, break into [i, m] as one pile and [m + 1, j] as k - 1 piles
                        if (dp[m + 1][j][k - 1] != INT_MAX) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
                        }
                    }
                }
                if (dp[i][j][K] != INT_MAX) {
                    dp[i][j][1] = dp[i][j][K] + prefixSum[j + 1] - prefixSum[i];
                }
            }
        }

        return dp[0][n -1][1];
    }
};
