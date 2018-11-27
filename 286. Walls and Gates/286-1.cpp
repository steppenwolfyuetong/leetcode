/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2 ^ 31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647. Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF 
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

//从INT_MAX开始BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        if(rooms.empty() || rooms.front().empty())
            return;
        int m = rooms.size();
        int n = rooms.front().size();

        vector<vector<bool> > visited;
        for(int i = 0; i < m; i++)
        {
            vector<bool> temp(n, false);
            visited.push_back(temp);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == INT_MAX)
                    rooms[i][j] = bfs(rooms, visited, i, j, m, n);
    }

    int bfs(vector<vector<int> >& rooms, vector<vector<bool> >& visited, int i, int j, int m, int n)
    {
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1 || rooms[i][j] == -1)
            return INT_MAX;
        if(rooms[i][j] == 0)
            return 0;
        if(visited[i][j])
            return rooms[i][j];

        visited[i][j] = true;
        if(rooms[i][j] > 0 && rooms[i][j] < INT_MAX)
            return rooms[i][j];

        int up = bfs(rooms, visited, i - 1, j, m, n);
        int down = bfs(rooms, visited, i + 1, j, m, n);
        int left = bfs(rooms, visited, i, j - 1, m, n);
        int right = bfs(rooms, visited, i, j + 1, m, n);
        
        visited[i][j] = false;

        int rt = min(min(up, down), min(left, right));
        return rt == INT_MAX ? rt : rt + 1;
    }
};

int main()
{
    int m = 4;
    int n = 4;
    int array[m][n] = {{INT_MAX, -1, 0, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX, -1}, {INT_MAX, -1, INT_MAX, -1}, {0, -1, INT_MAX, INT_MAX}};
    vector<vector<int> > rooms;
    for(int i = 0; i < m; i++)
    {
    	vector<int> temp;
        for(int j = 0; j < n; j++)
        {
            temp.push_back(array[i][j]);
        }
        rooms.push_back(temp);
    }
    
    Solution s;
    s.wallsAndGates(rooms);
    
    for(int i = 0; i < m; i++)
    {
    	for(int j = 0; j < n; j++)
    	{
    		cout << rooms[i][j] << ' ';
		}
		cout << endl;
	}
    
    return 0;
}

