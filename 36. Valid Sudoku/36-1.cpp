class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board.front().size() != 9) {
            return false;
        }

        int n = 9;

        // row
        for (int i = 0; i < n; i++) {
            if (!valid(board[i])) {
                return false;
            }
        }

        for (int j = 0; j < n; j++) {
            vector<char> col;
            for (int i = 0; i < n; i++) {
                col.emplace_back(board[i][j]);
            }
            if (!valid(col)) {
                return false;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = 3 * i, y = 3 * j;
                vector<char> box = {board[x][y], board[x+1][y], board[x+2][y], 
                                    board[x][y+1], board[x+1][y+1], board[x+2][y+1], 
                                    board[x][y+2], board[x+1][y+2], board[x+2][y+2]};
                if (!valid(box)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(vector<char>& seq) {
        set<char> dict(seq.begin(), seq.end());
        int dot = count(seq.begin(), seq.end(), '.');
        return dict.size() - 1 + count == seq.size();
    }
};
