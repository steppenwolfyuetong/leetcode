/*
https://leetcode.com/problems/regions-cut-by-slashes/discuss/205680/JavaC%2B%2BPython-Split-4-parts-and-Union-Find

Split a cell in to 4 parts like this.
We give it a number top is 1, right is 2, bottom is 3 left is 4.

Two adjacent parts in different cells are contiguous regions.
In case '/', top and left are contiguous, botton and right are contiguous.
In case '\\', top and right are contiguous, bottom and left are contiguous.
In case ' ', all 4 parts are contiguous.
*/

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        n_ = grid.size();
        visited_ = vector<vector<vector<bool>>>(n_, vector<vector<bool>>(n_, vector<bool>(4, false)));
        int result = 0;

        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < n_; j++) {
                for (int k = 0; k < 4; k++) {
                    if (!visited_[i][j][k]) {
                        dfs(i, j, k, grid);
                        result++;
                    }
                }
            }
        }
        return result;
    }
private:
    void dfs(int row, int col, int index, vector<string>& grid) {
        if (row < 0 || row >= n_ || col < 0 || col >= n_ || visited_[row][col][index]) {
            return;
        }
        visited_[row][col][index] = true;

        if (grid[row][col] == '/') {
            vector<int> delta = slash_[index];
            dfs(row + delta[0], col + delta[1], delta[2], grid);
            delta = neighbor_[index];
            dfs(row + delta[0], col + delta[1], delta[2], grid);
        } else if (grid[row][col] == '\\') {
            vector<int> delta = antislash_[index];
            dfs(row + delta[0], col + delta[1], delta[2], grid);
            delta = neighbor_[index];
            dfs(row + delta[0], col + delta[1], delta[2], grid);
        } else {
            visited_[row][col] = vector<bool>(4, true);                 // mark all of the four parts visited
            for (const auto& neigh : neighbor_) {                       // visit all parts of neighbor_
                vector<int> delta = neigh.second;
                dfs(row + delta[0], col + delta[1], delta[2], grid);
            }
        }
    }

    int n_;
    vector<vector<vector<bool>>> visited_;
    // grid[i][j] is /, save the corresponding part
    unordered_map<int, vector<int>> slash_ = {{0, {0, 0, 3}}, {3, {0, 0, 0}}, {1, {0, 0, 2}}, {2, {0, 0, 1}}};
    // grid[i][j] is \, save the corresponding part
    unordered_map<int, vector<int>> antislash_ = {{0, {0, 0, 1}}, {3, {0, 0, 2}}, {1, {0, 0, 0}}, {2, {0, 0, 3}}};
    // save the corresponding part in neighbor cell
    unordered_map<int, vector<int>> neighbor_ = {{0, {-1, 0, 2}}, {2, {1, 0, 0}}, {3, {0, -1, 1}}, {1, {0, 1, 3}}};
};

