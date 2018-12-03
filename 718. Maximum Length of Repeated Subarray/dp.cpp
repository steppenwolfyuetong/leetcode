class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        /*
        dp[i][j] max length between A[0:i), B[0:j), (max lenght between first i letters of A and first j letters of B)
        dp[0][0] = 0
        if A[i-1] == B[j-1]: 
            dp[i][j] = dp[i-1][j-1] + 1
        */
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int result = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};
