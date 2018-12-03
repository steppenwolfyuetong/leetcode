#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;

        int m = matrix.size(), n = matrix.front().size();
        vector<vector<int>> cache(m, vector<int>(n, 0));              // longest increasing path starts with matrix[i][j]

        int result = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(i, j, cache, matrix));
            }
        }
        return result;
    }

    int dfs(int i, int j, vector<vector<int>> &cache, vector<vector<int>> &matrix) {
        if (cache[i][j] != 0) {
            return cache[i][j];
        }

        int result = 1;
        vector<vector<int>> dirs{vector<int>{0,1}, vector<int>{0,-1}, vector<int>{1,0}, vector<int>{-1,0}};
        for (auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (valid(x, y, matrix) && matrix[i][j] < matrix[x][y]) {
                result = max(result, 1 + dfs(x, y, cache, matrix));
            }
        }
        cache[i][j] = result;
        return result;
    }

    bool valid(int i, int j, vector<vector<int>> &board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    //vector<vector<int>> matrix{{9,9,4}, {6,6,8}, {2,1,1}};
    vector<vector<int>> matrix{{9,8,7}, {4,5,6}, {3,2,1}};
    cout << s->longestIncreasingPath(matrix) << endl;
    return 0;
}

