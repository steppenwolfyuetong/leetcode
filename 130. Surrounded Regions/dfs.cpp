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
    // TLE
    //
    // dfs for each O, mark F if it can not be captured, the algorithm is write
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty())
            return;
        vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'O') {
                    dfs(i, j, visited, board);
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'F') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
private:
    bool dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &board) {
        if (board[i][j] == 'X') {
            return true;
        } else if(board[i][j] == 'F') {
            return false;
        }
        if (visited[i][j]) {
            return true;
        }

        vector<vector<int>> dirs {vector<int> {-1, 0}, vector<int> {1, 0}, vector<int> {0, -1}, vector<int> {0, 1}};

        visited[i][j] = true;
        bool flag = true;
        for (auto& dir : dirs) {
            auto x = i + dir[0];
            auto y = j + dir[1];
            // if is ok of four direction, it can be captured, otherwise mark it of 'F'
            if (valid(x, y, board) && dfs(x, y, visited, board)) {
                ;            
            } else {
                flag = false;
                break;
            }
        }
        visited[i][j] = false;

        if (flag) {
            board[i][j] = 'X';
        } else {
            board[i][j] = 'F';
        }

        return flag;
    }

    bool valid(int i, int j, vector<vector<char>> &board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<char>> board{vector<char> {'O','X','X','X'}, vector<char> {'X','O','X','X'}, vector<char>{'X','X','O','X'}, vector<char> {'X','X','X','X'}};
    s->solve(board);
    display(board);
    return 0;
}
