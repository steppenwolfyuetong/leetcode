#include "../leetcode.h"

// wrong
class Solution {
public:
    int deliver(vector<vector<char>>& grid) {
        m_ = grid.size();
        n_ = grid.front().size();

        for(int i = 0; i < m_; i++) {
            for(int j = 0; j < n_; j++) {
                if(grid[i][j] == 'S') {
                    start_ = {i, j};
                } else if (grid[i][j] == 'G') {
                    end_= {i, j};
                } else if (grid[i][j] == 'X') {
                    checkpoints_.insert({i, j});
                }
            }
        }
        dfs(grid,start_, 0);
        return 0;
    }

    bool dfs(vector<vector<char>>& grid, pair<int, int> cur, int steps) {
        if (cur == end_ && checkpoints_.empty()) {
            return true;
        }

        cout << cur.first << " " << cur.second << endl;

        if (checkpoints_.count(cur)) {
            checkpoints_.erase(cur);
        }

        for (pair<int, int> dir : dirs_) {
            pair<int, int> temp = {cur.first + dir.first, cur.second + dir.second};
            if (temp.first < 0 || temp.first >= m_ || temp.second < 0 || temp.second >= n_ || grid[temp.first][temp.second] == '#') {
                continue;
            }
            if (dfs(grid, temp, steps + 1)) {
                cout << steps + 1 << endl;
                return true;
            }
        }
        return false;
    }
private:
    vector<pair<int, int>> dirs_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    set<pair<int, int>> checkpoints_;
    pair<int, int> start_ = make_pair(-1, -1);
    pair<int, int> end_ = make_pair(-1, -1);
    int m_;
    int n_;
};

int main()
{
    /*
    vector<vector<char>> grid = {
        {'.','.','.','.','G'},
        {'.','.','.','.','.'},
        {'.','#','X','#','.'},
        {'S','#','X','#','X'}
    };
    */
    vector<vector<char>> grid = {
        {'#','G','#'},
        {'X','X','X'},
        {'#','S','#'},
    };

    Solution *s = new Solution();
    cout << s->deliver(grid) << endl;
    return 0;
}
