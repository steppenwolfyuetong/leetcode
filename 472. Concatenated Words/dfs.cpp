#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if (words.empty()) 
            return result; 
        sort(words.begin(), words.end(), [&](const string& str1, const string& str2) { return str1.size() < str2.size(); });
        
        unordered_set<string> cache;
        for (auto& word : words) {
            if (dfs(word, 0, cache)) {
                result.push_back(word);
            } else {
                cache.insert(word); 
            }
        }
        
        return result;
    }

    bool dfs(string word, int start, unordered_set<string>& cache) {
        if (word.empty()) {
            return false;
        }
        if (start == word.length()) {
            return true;
        }

        for (int end = start + 1; end <= word.length(); end++) {
            if (cache.find(word.substr(start, end - start)) != cache.end()) {
                if (dfs(word, end, cache)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution *s = new Solution;
    vector<string> dict{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    for (auto& result : s->findAllConcatenatedWordsInADict(dict))
        cout << result << endl;

    /*
    unordered_set<string> xxx{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    cout << s->dfs("dogcatsdog", 0, xxx);
    */

    return 0;
}
