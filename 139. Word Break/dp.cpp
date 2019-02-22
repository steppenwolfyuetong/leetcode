/*
 *  dp[i]: s[0,i) can be expressed by dict
 *  dp[i] depends on all smaller problems (dp[0], dp[1], ... dp[i-1])
 */



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        // i is the break index
        for (int i = 1; i <= s.length(); i++) {
            // faster when dict's scale is huge
            for (int j = 0; j < i; j++) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        /*
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
        */
        return dp[s.length()];
    }
};

