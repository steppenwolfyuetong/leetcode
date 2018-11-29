#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void display(vector<vector<T>> &board) {
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    // 1. dfs of each O on for edges, mark adjacent O of F.
    // 2. the rest O on the board can be capatured, convert F back to O, and O to X.
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty())
            return;
        int m = board.size(), n = board.front().size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][n-1] == 'O')
                dfs(i, n - 1, board);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);
            if (board[m-1][j] == 'O')
                dfs(m - 1, j, board);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'F') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void dfs(int i, int j, vector<vector<char>> &board) {
        board[i][j] = 'F';
        vector<vector<int>> dirs {vector<int> {-1, 0}, vector<int> {1, 0}, vector<int> {0, -1}, vector<int> {0, 1}};
        for (auto& dir : dirs) {
            auto x = i + dir[0];
            auto y = j + dir[1];
            if (valid(x, y, board) && board[x][y] == 'O') {
                dfs(x, y, board);            
            }        
        }
    }

    bool valid(int i, int j, vector<vector<char>> &board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<char>> board{vector<char> {'X','X','X','X'}, vector<char> {'X','O','O','X'}, vector<char>{'X','X','O','X'}, vector<char> {'X','X','O','X'}};
    s->solve(board);
    display(board);
    return 0;
}
