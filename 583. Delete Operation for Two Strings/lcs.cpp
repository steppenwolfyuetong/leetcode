// To make them identical, just find the longest common subsequence. 
// The rest of the characters have to be deleted from the both the strings, which does not belong to longest common subsequence.
//
// dp[i][j]: lcs between word1[0,i) and word2[0,j)
// dp[i][j] = word1[i-1] == word2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1])

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // dp[m][n] is LCS of word1 and word2
        // so we need to delete m - dp[m][n] letters from word1, and delete n - dp[m][n] letters from word2
        return m + n - 2 * dp[m][n];
    }
};

