#include <climits>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return bfs(maze, make_pair(start[0], start[1]), make_pair(destination[0], destination[1]));
    }

    int bfs(vector<vector<int>> &maze, pair<int, int> start, pair<int, int> end)
    {
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start.first][start.second] = 0;
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
                int dis = distance[x][y];
                while(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0)
                {
                    x += dir.first;
                    y += dir.second;
                    ++dis;
                }
                x -= dir.first;
                y -= dir.second;
                --dis;

                if(dis < distance[x][y])
                {
                    distance[x][y] = dis;
                    next.push(make_pair(x, y));
                }
            }
        }

        return distance[end.first][end.second];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> maze = {{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,1,0}, {1,1,0,1,1}, {0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {4,4};
    cout << s->shortestDistance(maze, start, destination) << endl;
    return 0;
}
