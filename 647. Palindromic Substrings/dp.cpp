class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        // dp[i][j] represents if s[i,j] is palindromic substrings
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (j - i <=2 || dp[i + 1][j - 1]);
                }
                if (dp[i][j]) {
                    result++;
                }
            }
        }
        return result;
    }
};
