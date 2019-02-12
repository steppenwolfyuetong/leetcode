class UnionFindSet {
public:
    UnionFindSet(int n) {
        parent_ = vector<int>(n, 0);
        rank_ = vector<int>(n, 0);

        for (int i = 0; i < n; i++) {
            parent_[i] = i;
        }
    }

    int Find(int x) {
        if (x != parent_[x]) {
            parent_[x] = Find(parent_[x]);
        }
        return parent_[x];
    }

    // Merge two set, return false if x and y already in same set
    bool Union(int x, int y) {
        int px = Find(x), py = Find(y);
        if (px == py) {
            return false;
        }

        if (rank_[px] > rank_[py]) {
            parent_[py] = px;
        } else if (rank_[px] < rank_[py]) {
            parent_[px] = py;
        } else {
            parent_[px] = py;
            rank_[py]++;
        }

        return true;
    }

private:
    vector<int> parent_;
    vector<int> rank_;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }
        UnionFindSet ufs(M.size());
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M.size(); j++) {
                if (M[i][j] == 1) {
                    ufs.Union(i, j);
                }
            }
        }

        unordered_set<int> root;
        for (int i = 0; i < M.size(); i++) {
            root.insert(ufs.Find(i));
        }
        return root.size();
    }
};
