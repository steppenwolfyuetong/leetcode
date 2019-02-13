#include <vector>
#include <iostream>
using namespace std;

class UnionFindSet {
public:
    UnionFindSet(int k, vector<vector<char>>& grid) {
        ranks_ = vector<int>(k, 0);        
        parents_ = vector<int>(k, -1);                
        islands_ = 0;
        
        int m = grid.size(), n = grid.front().size();        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int index = i * n + j;
                    parents_[index] = index;
                    islands_++;
                }
            }
        }
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    void Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu != pv) {
            parents_[pu] = pv;
            islands_--;
        }
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
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }

        int m = grid.size(), n = grid.front().size();        
        UnionFindSet ufs(m * n, grid);

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    for (const auto& dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
                            continue;
                        } else {
                            ufs.Union(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }
        return ufs.islands_;
    }
};

int main()
{
    vector<vector<char>> grid;
    grid.push_back(vector<char>{'1','1','1','1','0'});
    grid.push_back(vector<char>{'1','1','0','1','0'});
    grid.push_back(vector<char>{'1','1','0','0','0'});
    grid.push_back(vector<char>{'0','0','0','0','0'});

    Solution *s = new Solution();
    cout << s->numIslands(grid) << endl;
    return 0;
}
