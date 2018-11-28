class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        sort(words.begin(), words.end(), [&](const string& s1, const string& s2) { return s1.length() < s2.length();});
        unordered_set<string> dict;
        for (auto& word : words) {
            if (helper(word, dict)) {
                result.emplace_back(word);
            }
            dict.insert(word);
        }
        return result;
    }
private:
    bool helper(string s, unordered_set<string>& dict) {
        if (dict.empty())
            return false;

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for(int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j])
                    continue;
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

