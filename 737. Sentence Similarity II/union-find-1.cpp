/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if “great” and “good” are similar, and “fine” and “good” are similar, then “great” and “fine” are similar.

Similarity is also symmetric. For example, “great” and “fine” being similar is the same as “fine” and “great” being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/

class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n, 0);        
        parents_ = vector<int>(n, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        // Meger low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu])
            parents_[pu] = pv;           
        else if (ranks_[pu] > ranks_[pv])
            parents_[pv] = pu;
        else {
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        UnionFindSet s(pairs.size() * 2);

        unordered_map<string, int> indies;          // word to index

        for (const auto& pair : pairs) {
            int u = getIndex(pair.first, indies, true);
            int v = getIndex(pair.second, indies, true);
            s.Union(u, v);
        }

        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            int u = getIndex(words1[i], indies);
            int v = getIndex(words2[i], indies);
            if (u < 0 || v < 0) return false;
            if (s.Find(u) != s.Find(v)) return false;
        }

        return true;
    }
private:
    int getIndex(const string& word, unordered_map<string, int>& indies, bool create = false) {
        auto it = indies.find(word);
        if (it == indies.end()) {
            if (!create) return INT_MIN;
            int index = indies.size();
            indies.emplace(word, index);
            return index;
        }

        return it->second;
    }
};

