class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Mark evert word as breakable.
        for (const string& word : wordDict)
            mem_.emplace(word, true);

        // Query the answer of the original string.
        return wordBreak(s);
    }

    bool wordBreak(const string& s) {
        if (mem_.count(s)) {
            return mem_[s];
        }

        // Try every break point.
        for (int j = 1; j < s.length(); j++) {         
            auto it = mem_.find(s.substr(0, j));
            // Find the solution for s.
            if (it != mem_.end() && it->second && wordBreak(s.substr(j))) {
                mem_[s] = true;
                return true;
            }
        }

        // No solution for s, memorize and return.
        mem_[s] = false;
        return false;
    }
private:
    unordered_map<string, bool> mem_;
};

