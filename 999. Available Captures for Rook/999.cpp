class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        auto check = [&](int i, int j) {
            int result = 0;
            for (const auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                while (0 <= x && x < board.size() && 0 <= y && y < board.front().size()) {
                    if (board[x][y] == 'p') {
                        result++;
                        break;
                    } else if (board[x][y] == 'B') {
                        break;
                    }
                    x += dir[0];
                    y += dir[1];
                }
            }
            return result;
        };

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    return check(i, j);
                }
            }
        }
        return 0;
    }
};
