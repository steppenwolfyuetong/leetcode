class Solution {
public:
    /*
     * Alice stop when she gets K or more points, each draw get points with [1,W], so the point range is [K, K + W - 1]
     *
     * dp[i]: sum of probability to get [0, i] points, when get K or more points.
     * so the probability to get i points is dp[i] - dp[i - 1]
     * 
     * result: dp[N] - dp[K-1]
     *
     * dp[0] = 1, when get 0 points, probability is 1.
     *
     * dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - W - 1]) / W
     */
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1.0;
        }
        int max = K + W - 1;
        vector<double> dp(max + 1, 0);
        dp[0] = 1.0;
        
        for (int i = 1; i <= max; i++) {
            dp[i] = dp[i - 1];
            if (i <= W) {
                dp[i] += dp[i - 1] / W;
            } else {
                dp[i] += (dp[i - 1] - dp[i - W - 1]) / W;
            }

            if (i > K) {
                dp[i] -= (dp[i - 1] - dp[K - 1]) / W;
            }
        }

        return dp[N] - dp[K - 1];
    }
};
