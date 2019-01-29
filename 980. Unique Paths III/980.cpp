#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }
        m_ = grid.size(), n_ = grid.front().size();
        vector<vector<bool>> visited(m_, vector<bool>(n_, false));
        
        int x = 0, y = 0, count = 0;
        for (int i = 0; i < m_; i++) {
            for (int j = 0; j < n_; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    visited[i][j] = true;
                    count++;
                } else if (grid[i][j] == -1) {
                    visited[i][j] = true;
                    count++;
                }
            }
        }
        return dfs(grid, x, y, count, visited);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int count, vector<vector<bool>>& visited) {
        if (grid[x][y] == 2) {
            return count == m_ * n_ ? 1 : 0;
        }

        int paths = 0;
        visited[x][y] = true;
        for (const auto& dir : dirs) {
            int xxx = x + dir.first;
            int yyy = y + dir.second;
            if (valid(xxx, yyy, visited)) {
                paths += dfs(grid, xxx, yyy, count + 1, visited);
            }
        }
        visited[x][y] = false;
        return paths;
    }

    bool valid(int x, int y, vector<vector<bool>>& visited) {
        if (x < 0 || y < 0 || x >= m_ || y >= n_ || visited[x][y]) {
            return false;
        }
        return true;
    }
private:
    int m_;
    int n_;
    const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
