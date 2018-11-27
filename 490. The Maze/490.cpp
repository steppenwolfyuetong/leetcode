#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty())
            return false;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        return dfs(maze, visited, make_pair(start[0], start[1]), make_pair(destination[0], destination[1]));
    }

    bool dfs(vector<vector<int>> &maze, vector<vector<bool>> &visited, pair<int, int> start, pair<int, int> end)
    {
        if(start == end)
            return true;
        if(visited[start.first][start.second])
            return false;

        visited[start.first][start.second] = true;
        
        vector<pair<int, int>> dirs{make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
        for(auto dir : dirs)
        {
            int x = start.first, y = start.second;
            while(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0)
            {
                x += dir.first;
                y += dir.second;
            }
            x -= dir.first;
            y -= dir.second;

            if(x == end.first && y == end.second)
                return true;

            if(dfs(maze, visited, make_pair(x, y), end))
                return true;
        }

        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> maze = {{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,1,0}, {1,1,0,1,1}, {0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {4,4};
    cout << s->hasPath(maze, start, destination) << endl;
    return 0;
}
