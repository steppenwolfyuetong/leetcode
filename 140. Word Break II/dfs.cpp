#include <vector>
#include <string>
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
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (auto& word : dict) {
            if (s.find(word) == 0) {
                vector<string> post = dfs(s.substr(word.length()), dict, cache);
                for (auto& suffix : post) {
                    result.push_back(word + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }

        cache[s] = result;
        return result;
    }
};


