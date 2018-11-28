class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // dp[i] represents ways to decode a string of size i
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        // for dp[i]
        // if current digit is valid, then add dp[i-1]
        // if pre + current is valid, then add dp[i-2]
        for (int i = 2; i <= n; i++) {
            int first = stoi(s.substr(i - 1, 1));       // 1 <= first <= 9 is valid
            int second = stoi(s.substr(i - 2, 2));      // 10 <= second <= 26 is valid
            
            if (1 <= first && first <= 9)
                dp[i] += dp[i-1];
            if (10 <= second && second <= 26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
