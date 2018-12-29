/*
    dp[k][i][j]: the maximum number of strings that you can form with given i 0s and j 1s with first k str
    dp[k][i][j] = max(dp[k-1][i][j], dp[k-1][i - zeros][j - ones] + 1)
    dp[0][0][0] = 0
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int k = 1; k <= strs.size(); k++) {
            int zeros = 0, ones = 0;
            for (auto c : strs[k - 1]) {
                if (c == '0')
                    zeros++;
                else if (c == '1')
                    ones++;
            }
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i >= zeros && j >= ones) {
                        dp[k][i][j] = max(dp[k-1][i][j], dp[k-1][i - zeros][j - ones] + 1);
                    } else {
                        dp[k][i][j] = dp[k-1][i][j];
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }

    // 可以降维至dp[i][j], i和j需要从大到小进行遍历
};
