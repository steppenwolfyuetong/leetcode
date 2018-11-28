class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> table(s.length(), false);
        return dfs(s, wordDict, table, 0);
    }

    bool dfs(string s, vector<string>& dict, vector<bool> &table, int index) {
        if (index == s.length())
            return true;
        if (table[index])
            return false;

        for (auto& word : dict) {
            if (index + word.length() <= s.length() && (s.substr(index, word.length()) == word)) {
                if (dfs(s, dict, table, index + word.length())) {
                    return true;
                }
            }
        }

        table[index] = true;
        return false;
    }
};

