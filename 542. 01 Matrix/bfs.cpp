#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*
1. At beginning, set cell value to Integer.MAX_VALUE if it is not 0.
2. If newly calculated distance >= current distance, then we don't need to explore that cell again.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        queue<vector<int>> queue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    queue.push(vector<int>{i, j});
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        
        vector<vector<int>> dirs {vector<int> {-1, 0}, vector<int> {1, 0}, vector<int> {0, -1}, vector<int> {0, 1}};
        
        while (!queue.empty()) {
            vector<int> cell = queue.front();
            queue.pop();
            for (auto& dir : dirs) {
                int r = cell[0] + dir[0];
                int c = cell[1] + dir[1];
                if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= matrix[cell[0]][cell[1]] + 1) {
                    continue;
                }
                queue.push(vector<int>{r, c});
                matrix[r][c] = matrix[cell[0]][cell[1]] + 1;
            }
        }
        
        return matrix;
    }
};
