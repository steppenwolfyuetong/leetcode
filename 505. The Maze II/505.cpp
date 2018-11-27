class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty())
            return false;
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start[0]][start[1]] = 0;
        dfs(maze, distance, make_pair(start[0], start[1]), make_pair(destination[0], destination[1]));
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }

    void dfs(vector<vector<int>> &maze, vector<vector<bool>> &distance, pair<int, int> start, pair<int, int> end)
    {
        if(start == end)
            return;

        vector<pair<int, int>> dirs{make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
        for(auto dir : dirs)
        {
            int x = start.first, y = start.second;
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
                dfs(maze, distance, make_pair(x, y), end);
            }
        }

        return false;
    }
}
