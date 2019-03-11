/*
DP, use dp[k][i] to denote the largest average sum of partitioning first i elements into k groups.

Init
dp[1][i] = sum(a[0] ~ a[i – 1]) / i, for i in 1, 2, … , n.

Transition
dp[k][i] = max(dp[k – 1][j] + sum(a[j] ~ a[i – 1]) / (i – j)) for j in k – 1,…,i-1.

that is find the best j such that maximize dp[k][i]

largest sum of partitioning first j elements (a[0] ~ a[j – 1]) into k – 1 groups (already computed)
+ average of a[j] ~ a[i – 1] (partition a[j] ~ a[i – 1] into 1 group).

Answer
dp[K][n]
*/

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        const int n = A.size();
        vector<vector<double>> dp(K + 1, vector<double>(n + 1, 0.0));
        vector<double> sums(n + 1, 0.0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + A[i - 1];
            dp[1][i] = static_cast<double>(sums[i]) / i;
        }
        for (int k = 2; k <= K; ++k)                            // k groups
            for (int i = k; i <= n; ++i)                        // i elements
                for (int j = k - 1; j < i; ++j)                 // j is break point
                    dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sums[i] - sums[j]) / (i - j));
        return dp[K][n];
    }
};
