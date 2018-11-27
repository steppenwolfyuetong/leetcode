#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0, neighbours = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    islands++;
                    if(i + 1 < grid.size() && grid[i+1][j] == 1)
                        neighbours++;
                    if(j + 1 < grid[i].size() && grid[i][j+1] == 1)
                        neighbours++;
                }
            }
        }
        return islands * 4 - neighbours * 2;
    }

    // dfs
    int islandPerimeter1(vector<vector<int>>& grid) {
        int rt = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    helper(grid, visited, i, j, rt);
                    return rt;
                }
            }
        }
        return 0;
    }

    void helper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int &ans)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1 || visited[x][y])
            return;
        visited[x][y] = true;

        if(x - 1 < 0 || grid[x-1][y] == 0)
            ans += 1;
        if(x + 1 >= grid.size() || grid[x+1][y] == 0)
            ans += 1;
        if(y - 1 < 0 || grid[x][y-1] == 0)
            ans += 1;
        if(y + 1 >= grid[0].size() || grid[x][y+1] == 0)
            ans += 1;

        helper(grid, visited, x-1, y, ans);
        helper(grid, visited, x+1, y, ans);
        helper(grid, visited, x, y-1, ans);
        helper(grid, visited, x, y+1, ans);
        return;
    }
};

int main()
{
    vector<vector<int>> nums;

    int arr1[4] = {0,1,0,0};
    vector<int> vec1(arr1, arr1 + 4);
    nums.push_back(vec1);
    int arr2[4] = {1,1,1,0};
    vector<int> vec2(arr2, arr2 + 4);
    nums.push_back(vec2);
    int arr3[4] = {0,1,0,0};
    vector<int> vec3(arr3, arr3 + 4);
    nums.push_back(vec3);
    int arr4[4] = {1,1,0,0};
    vector<int> vec4(arr4, arr4 + 4);
    nums.push_back(vec4);

    Solution *s = new Solution();
    cout << s->islandPerimeter(nums) << endl;
    cout << s->islandPerimeter1(nums) << endl;
}
