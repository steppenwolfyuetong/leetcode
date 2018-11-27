#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty())
            return false;
        return bfs(maze, make_pair(start[0], start[1]), make_pair(destination[0], destination[1]));
    }

    bool bfs(vector<vector<int>> &maze, pair<int, int> start, pair<int, int> end)
    {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        visited[start.first][start.second] = true;
        queue<pair<int, int>> next;
        next.push(start);

        vector<pair<int, int>> dirs{make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
        while(!next.empty())
        {
            pair<int, int> cur = next.front();
            next.pop();
            for(auto dir : dirs)
            {
                int x = cur.first, y = cur.second;
                while(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0)
                {
                    x += dir.first;
                    y += dir.second;
                }
                x -= dir.first;
                y -= dir.second;

                if(visited[x][y])
                    continue;

                visited[cur.first][cur.second] = true;

                if(x == end.first && y == end.second)
                    return true;
                else
                    next.push(make_pair(x, y));
            }
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
