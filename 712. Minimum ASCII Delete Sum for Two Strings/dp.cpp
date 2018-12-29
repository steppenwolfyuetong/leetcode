/*
 *  dp[i][j] is lowest ASCII sum of deleted characters to make two strings equal between s1[0,i) and s2[0,j).
 *  
 *  init state:
 *  dp[0][0] = 0
 *  dp[i][0] = sum[s1[0,i)]
 *  dp[0][j] = sum[s2[0,j)]
 *
 *
 *  1. s1[i - 1] == s2[j-1]
 *     dp[i][j] = dp[i-1][j-1]
 *  2. s1[i - 1] != s2[j-1] 
 *     dp[i][j] = min(dp[i][j-1] + ascii(s2[j-1]), dp[i-1][j] + ascii(s1[i-1]));
 *                      delete from s2                  delete from s1
 */



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + ascii(s1[i-1]);    
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] + ascii(s2[j-1]);
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n ; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1] + ascii(s2[j-1]), dp[i-1][j] + ascii(s1[i-1]));
            }
        }
        return dp[m][n];
    }
private:
    int ascii(char s) {
        return 97 + s - 'a';
    }
};
