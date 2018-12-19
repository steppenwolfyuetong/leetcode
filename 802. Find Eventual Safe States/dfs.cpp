/*
0:have not been visited
1:safe
2:unsafe    (node is in cycle, or node will go to a cycle eventually)

When we travel a path, we mark the node with 2 which represents having been visited, and when we encounter a node which results in a cycle, we return false, all node in the path stays 2 and it represents unsafe.
And in the following traveling, whenever we encounter a node which points to a node marked with 2, we know it will results in a cycle, so we can stop traveling.
On the contrary, when a node is safe, we can mark it with 1 and whenever we encounter a safe node, we know it will not results in a cycle.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe;
        if (graph.empty()) {
            return safe;
        }

        vector<int> state(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(graph, i, state)) {
                safe.push_back(i);
            }
        }
        return safe;
    }

    bool dfs(vector<vector<int>>& graph, int start, vector<int>& state) {
        if (state[start] != 0) {
            return state[start] == 1;
        }

        state[start] = 2;
        for (auto& neigh : graph[start]) {
            if (!dfs(graph, neigh, state)) {        // if any neighbor of current node is unsafe, the node is unsafe
                return false;
            }
        }
        state[start] = 1;
        return true;
    }
};
