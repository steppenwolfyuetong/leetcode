/*
cur[]: current route
visited[]: visit times of each node, in current route
count: how many nodes are visited

In each dfs function call, visit all the nodes which has the least visit times.
When the count is equal to graph.size(), update the optimum result.

And make a pruning:

when cur.size() >= result, it need not to continue dfs, just exit this funtion.
*/
class Solution {
public:
    int result;
    void dfs(vector<vector<int>>& graph, vector<int>& cur, vector<int>& visited, int count) {
        if (result == graph.size()) return;
        if (count == graph.size()) {
            result = min(result, int(cur.size()));
            return;
        }
        if (cur.size() >= result) return;
        int pos = cur.back();

        int minv = INT_MAX;
        for (auto n : graph[pos]) minv = min(minv, visited[n]);
        for (auto n : graph[pos]) {
            if (visited[n] == minv) {
                cur.push_back(n);
                if (!visited[n]) count++;
                visited[n]++;
                dfs(graph, cur, visited, count);
                visited[n]--;
                if (!visited[n]) count--;
                cur.pop_back();
            }
        }
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        result = INT_MAX;
        vector<int> cur;
        vector<int> visited(graph.size(), 0);
        int count = 0;
        for (int i = 0; i < graph.size(); i++) {
            cur.push_back(i);
            visited[i]++;
            count++;
            dfs(graph, cur, visited, count);
            count--;
            visited[i]--;
            cur.pop_back();
        }
        return result - 1;
    }
};
