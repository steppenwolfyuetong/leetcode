#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // build graph
        vector<vector<pair<int, int>>> graph(N + 1);
        for (auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        vector<bool> visited(N + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, K});
        int u, v, w;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            u = p.second;
            if (visited[u])
                continue;
            for (auto& neigh : graph[u]) {
                v = neigh.first;
                w = neigh.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
            visited[u] = true;
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};
    cout << s->networkDelayTime(times, 4, 2) << endl;
}
