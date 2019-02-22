#include <set>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> cache;
        set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict, cache);
    }

    vector<string> dfs(string s, set<string>& dict, unordered_map<string, vector<string>>& cache) {
        if (cache.find(s) != cache.end())
            return cache[s];

        vector<string> result;
        for (int j = 1; j < s.size(); j++) {
            string cur = s.substr(0, j);
            if (dict.find(cur) != dict.end()) {
                if (j == s.size()) {                        // all matched
                    result.emplace_back(cur);
                } else {
                    vector<string> suffix = dfs(s.substr(j), dict, cache);
                    for (const auto& s : suffix) {
                        result.emplace_back(cur + " " + s);
                    }
                }
            }
        }

        cache[s] = result;
        return result;
    }
};

int main() {
    Solution s;
    vector<string> dict;
    vector<string> result;

    dict = {"cat", "cats", "and", "sand", "dog"};
    result = s.wordBreak("catsanddog", dict);
    cout << "!!!" << endl;
    for (const auto& xxx : result) {
        cout << xxx << endl;
    }

    dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    result = s.wordBreak("pineapplepenapple", dict);
    cout << "!!!" << endl;
    for (const auto& xxx : result) {
        cout << xxx << endl;
    }
    return 0;
}
