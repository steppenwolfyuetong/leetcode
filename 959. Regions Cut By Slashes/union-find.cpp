/*
https://leetcode.com/problems/regions-cut-by-slashes/discuss/205680/JavaC%2B%2BPython-Split-4-parts-and-Union-Find

Split a cell in to 4 parts like this.
We give it a number top is 1, right is 2, bottom is 3 left is 4.

Two adjacent parts in different cells are contiguous regions.
In case '/', top and left are contiguous, botton and right are contiguous.
In case '\\', top and right are contiguous, bottom and left are contiguous.
In case ' ', all 4 parts are contiguous.
*/

class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n, 0);        
        parents_ = vector<int>(n, 0);                
        islands_ = n;
        
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

        islands_--;
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }

    int islands_;
private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        n_ = grid.size();
        UnionFindSet ufs(n_ * n_ * 4);

        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < n_; j++) {
                if (i > 0) {                            // union up cell
                    ufs.Union(index(i, j, 0), index(i - 1, j, 2));
                }
                if (j > 0) {                            // union left cell
                    ufs.Union(index(i, j, 3), index(i, j - 1, 1));
                }

                if (grid[i][j] == '/') {
                    ufs.Union(index(i, j, 0), index(i, j, 3));
                    ufs.Union(index(i, j, 1), index(i, j, 2));
                } else if (grid[i][j] == '\\') {
                    ufs.Union(index(i, j, 0), index(i, j, 1));
                    ufs.Union(index(i, j, 2), index(i, j, 3));
                } else {
                    ufs.Union(index(i, j, 0), index(i, j, 1));
                    ufs.Union(index(i, j, 1), index(i, j, 2));
                    ufs.Union(index(i, j, 2), index(i, j, 3));
                }
            }
        }
        return ufs.islands_;
    }

    int index(int row, int col, int dir) {
        return (row * n_ + col) * 4 + dir;              // each cell has 4 parts
    }
private:
    int n_;
};
