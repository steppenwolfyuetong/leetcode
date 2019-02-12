#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    // dfs
    // For each edge {u, v}, use dfs to check whether u and v are already connected
    // O(n^2)
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph = buildGraph(edges);

        for (int i = edges.size() - 1; i > -1; i--) {
            int u = edges[i][0], v = edges[i][1];

            graph[u].erase(v);                  // remove the edges and check if still connected
            unordered_set<int> visited;
            if (hasPath(u, v, graph, visited)) {
                return edges[i];
            }
            graph[u].insert(v);
        }

        return {};
    }

    unordered_map<int, unordered_set<int>> buildGraph(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        return graph;
    }

    bool hasPath(int cur, int goal, unordered_map<int, unordered_set<int>> &graph, unordered_set<int> &visited) {
        if (cur == goal) {
            return true;
        }
        
        visited.insert(cur);
        for (const auto neigh : graph[cur]) {
            if (visited.count(neigh)) {
                continue;
            }
            if (hasPath(neigh, goal, graph, visited)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges;
    vector<int> result;

    edges = {{1,2}, {1,3}, {2,3}};
    result = s.findRedundantConnection(edges);
    cout << result[0] << result[1] << endl;

    edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    result = s.findRedundantConnection(edges);
    cout << result[0] << result[1] << endl;
}
