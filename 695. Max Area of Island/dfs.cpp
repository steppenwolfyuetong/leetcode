class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.front().size(), false));
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (grid[i][j] == 1) {
                    result = max(result, dfs(i, j, visited, grid));
                }
            }
        }
        return result;
    }
private:
    int dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid) {
        if (grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        int result = 1;
        visited[i][j] = true;

        vector<vector<int>> dirs{vector<int>{0,1}, vector<int>{0,-1}, vector<int>{1,0}, vector<int>{-1,0}};
        for (auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (valid(x, y, grid)) {
                result += dfs(x, y, visited, grid);
            }
        }
        return result;
    }

    bool valid(int i, int j, vector<vector<int>> &board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        return true;
    }
};

