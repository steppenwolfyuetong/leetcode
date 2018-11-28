/*
 * dp[i][j] sum of path end with A[i][j]
 * 
 * dp[i][j] = min(dp[i-1][j-1],dp[i-1][j], dp[i-1][j+1]) + A[i][j]
 */


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.empty()) {
            return 0;
        }

        int m = A.size(), n = A[0].size();
        vector<int> cur(n, 0), next(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    next[j] = min(cur[j], cur[j+1]) + A[i][j];
                } else if (j == n - 1) {
                    next[j] = min(cur[j-1], cur[j]) + A[i][j];
                } else {
                    next[j] = min(cur[j-1], min(cur[j], cur[j+1])) + A[i][j];
                }
            }
            swap(cur, next);
        }

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (cur[j] < result) {
                result = cur[j];
            }
        }
        return result;
    }
};
