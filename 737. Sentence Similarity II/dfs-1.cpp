// Author: Huahua
// Runtime 229 ms
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        g_.clear();
        ids_.clear();
        
        for (const auto& p : pairs) {
            g_[p.first].insert(p.second);
            g_[p.second].insert(p.first);
        }        
        
        // 用ids_保存一个word->id的map 检查的时候就检查id是否一致即可
        int id = 0;
        for (const auto& p : pairs) {
            if(!ids_.count(p.first)) dfs(p.first, ++id);
            if(!ids_.count(p.second)) dfs(p.second, ++id);
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            auto it1 = ids_.find(words1[i]);
            auto it2 = ids_.find(words2[i]);
            if (it1 == ids_.end() || it2 == ids_.end()) return false;
            if (it1->second != it2->second) return false;
        }
        
        return true;
    }
private:
    // dfs将类似单词标记为同一个id
    bool dfs(const string& curr, int id) {
        ids_[curr] = id;        
        for (const auto& next : g_[curr]) {
            if (ids_.count(next)) continue;
            if (dfs(next, id)) return true;
        }
        return false;
    }
    
    unordered_map<string, int> ids_;
    unordered_map<string, unordered_set<string>> g_;
};

