class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n, 0);        
        parents_ = vector<int>(n, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;

        islands = n;
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
        islands--;
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }

    int islands;
private:
    vector<int> parents_;
    vector<int> ranks_;
};
 
class Solution {
public:
    // The largest possible number of moves we can make = 
    // Total stones count - count of stones left = Total stones count - count of islands.
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFindSet ufs(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ufs.Union(i, j);
                }
            }
        }
        return n - ufs.islands;
    }
};
