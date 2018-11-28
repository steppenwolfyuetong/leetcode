/*
 *  dp[i][j] means the edit distance of between word1[0,i) and word2[0,j)
 * 
 *  init state:
 *  dp[0][0] = 0    (two empty strings are equal)
 *  dp[i][0] = i    (i != 0)
 *  dp[0][j] = j    (j != 0)
 *
 *  if dp[i][j] known, how to get dp[i + 1][j + 1]?
 *  1. if word1[i] == word2[j]
 *      dp[i + 1][j + 1] = dp[i][j]
 *  2. if word1[i] != word2[j]
 *      1) replace: dp[i + 1][j + 1] = dp[i][j] + 1
 *      2) insert one letter to word1: dp[i + 1][j + 1] = dp[i][j+1] + 1
 *      3) delete one letter from word1: dp[i + 1][j + 1] = dp[i+1][j] + 1
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
