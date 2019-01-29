#include <vector>
#include <iostream>
using namespace std;

// dp[x][y][state] = path start from (x, y) with state
// state is a bit map of nodes to visit
// the bit of 1 means unvisited, if all visited, state comes to 0

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m_ = grid.size();
        n_ = grid[0].size();

        int x = -1;
        int y = -1;
        int state = 0;
        cache_ = vector<vector<vector<short>>>(m_, vector<vector<short>>(n_, vector<short>(1 << m_ * n_, -1)));

        for (int i = 0; i < m_; i++) {
            for (int j = 0; j < n_; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                } else if (grid[i][j] == 0 || grid[i][j] == 2) {
                    state |= key(i, j);         // set unvisited of (i, j) in state
                }
            }
        }
        //cout << "initial state: " << hex << state << endl;
        return dfs(grid, x, y, state);
    }
private:
    int m_;
    int n_;
    vector<vector<vector<short>>> cache_;
    const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int key(int x, int y) {
        // (x, y) is (y * m + x)th element iterating by row
        return 1 << (y * m_ + x);
    }

    bool valid(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= m_ || y >= n_ || grid[x][y] == -1) {
            return false;
        }
        return true;
    }

    short dfs(vector<vector<int>>& grid, int x, int y, int state) {
        if (cache_[x][y][state] != -1) {
            return cache_[x][y][state];
        }

        if (grid[x][y] == 2) {
            //cout << "check state: " << hex << state << endl;
            return state == 0 ? 1 : 0;
        }

        int paths = 0;
        for (const auto& dir : dirs) {
            int xxx = x + dir.first;
            int yyy = y + dir.second;
            // (xxx, yyy) is valid, and needs to visit
            if (valid(grid, xxx, yyy) && (state & key(xxx, yyy))) {
                paths += dfs(grid, xxx, yyy, state ^ key(xxx, yyy));
            }
        }
        cache_[x][y][state] = paths;
        return paths;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> grid1{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << s->uniquePathsIII(grid1) << endl;
    vector<vector<int>> grid2{{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    cout << s->uniquePathsIII(grid2) << endl;
    vector<vector<int>> grid3{{1,0},{0,2}};
    cout << s->uniquePathsIII(grid3) << endl;

    return 0;
}
