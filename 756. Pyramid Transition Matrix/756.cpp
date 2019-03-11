#include "../leetcode.h"

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) {
            dict_[s.substr(0, 2)].emplace_back(s.back());
        }
        return dfs(bottom, 0, "");
    }

    bool dfs(string bottom, ssize_t start, string nextLevel){
        if (bottom.size() == 1) {
            return true;
        }

        // current level is possible, go to next level
        if (start == bottom.size() - 1) {
            return dfs(nextLevel, 0, "");
        }

        for (auto c : dict_[bottom.substr(start, 2)]) {
            if (dfs(bottom, start + 1, nextLevel + c)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<string, vector<char>> dict_;
};
