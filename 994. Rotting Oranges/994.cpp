#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return -1;
        }

        queue<pair<int, int>> rotting;
        int m = grid.size(), n = grid.front().size();
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rotting.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        int result = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!rotting.empty()) {
            int size = rotting.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> cur = rotting.front();
                rotting.pop();
                for (const auto& dir : dirs) {
                    int next_x = cur.first + dir[0];
                    int next_y = cur.second + dir[1];
                    if (isFresh(next_x, next_y, m, n, grid)) {
                        rotting.push({next_x, next_y}); 
                        grid[next_x][next_y] = 2;
                        fresh--;
                    }
                }
            }
            result++;
        }

        // Return the minimum number of minutes that must elapse until no cell has a fresh orange.
        // so we need to return result - 1;
        return fresh == 0 ? result - 1: -1;
    }

    bool isFresh(int x, int y, int m, int n, vector<vector<int>> &grid) {
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return false;
        }
        if (grid[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << s.orangesRotting(grid) << endl;
}
