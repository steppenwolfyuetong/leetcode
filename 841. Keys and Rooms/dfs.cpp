class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        unordered_set<int> visited;
        dfs(rooms, keys, visited, 0);
        return visited.size() == rooms.size();
    }

    void dfs(vector<vector<int>>& rooms, unordered_set<int> & keys, unordered_set<int> & visited, int cur) {
        if (visited.find(cur) != visited.end()) {
            return;
        }

        visited.insert(cur);
        for (auto& key : rooms[cur]) {
            keys.insert(key);
        }
        for (auto& next : keys) {
            dfs(rooms, keys, visited, next);
        }
    }

    // bfs
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> to_visit;
        to_visit.push(0);
        while(!to_visit.empty()) {
            int curr = to_visit.front();
            to_visit.pop();
            visited.insert(curr);
            for (int k : rooms[curr]) {
                if (visited.find(k) == visited.end()) 
                    to_visit.push(k);
            }
        }
        return visited.size() == rooms.size();
    }
};


