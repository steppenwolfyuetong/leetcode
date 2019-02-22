class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        int mod = 1E10 + 9;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
    }
};


