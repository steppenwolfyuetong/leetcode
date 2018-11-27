#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        if(grid[x][y] == '0')
            return;

        cout << x << ' ' << y << endl;

        grid[x][y] = '0';
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
    }
};

int main()
{
    vector<vector<char>> grid;
    grid.push_back(vector<char>{'1','1','1','1','0'});
    grid.push_back(vector<char>{'1','1','0','1','0'});
    grid.push_back(vector<char>{'1','1','0','0','0'});
    grid.push_back(vector<char>{'0','0','0','0','0'});

    Solution *s = new Solution();
    cout << s->numIslands(grid) << endl;
    return 0;
}
