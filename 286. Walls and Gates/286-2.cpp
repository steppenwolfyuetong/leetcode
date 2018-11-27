//从门开始BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0)
            return;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[0].size(); j++) {
                if(rooms[i][j] == 0) {
                    q.push(pair<int, int>(i, j));
                }
            }
        }
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto d : dir) {
                int i = x + d.first, j = y + d.second;
                if(i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() || rooms[i][j] <= rooms[x][y] + 1)
                    continue;
                rooms[i][j] = rooms[x][y] + 1;
                q.push(pair<int, int>(i, j));
            }
        }
    }
};
