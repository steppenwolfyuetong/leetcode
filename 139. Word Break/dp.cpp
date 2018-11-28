class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (auto& word : wordDict) {
                if (word.length() <= i) {
                    if (dp[i - word.length()] && (s.substr(i - word.length(), word.length()) == word)) {
                            dp[i] = true;
                            break;
                    }
                }
            }
        }
        /*
        for(int i = 1; i <= s.length(); i++) {
            // faster when dict's scale is huge
            for (int j = 0; j < i; j++) {
                if (!dp[j])
                    continue;
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        */
        return dp[s.length()];
    }
};

