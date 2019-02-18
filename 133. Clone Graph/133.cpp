#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// To clone a graph, you will need to traverse it. 
// Both BFS and DFS are for this purpose. But that is not all you need. 
// To clone a graph, you need to have a copy of each node and you need to avoid copying the same node for multiple times. 
// So you still need a mapping from an original node to its copy.

class Solution {
public:
    // same as 138, use a map to indicate relationship between old and copy node
    // bfs
    /*
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;        
        UndirectedGraphNode *result = new UndirectedGraphNode(node->label);
        dict[node] = result;

        queue<UndirectedGraphNode*> que;
        que.push(node);
        while (!que.empty()) {
            UndirectedGraphNode *cur = que.front();
            que.pop();
            for (const auto& neigh : cur->neighbors) {
                if (dict.find(neigh) == dict.end()) {
                    dict[neigh] = new UndirectedGraphNode(neigh->label);
                    que.push(neigh);
                }
                dict[cur]->neighbors.emplace_back(dict[neigh]);
            }
        }
        return result;
    }
    */

    // dfs
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;        
        dfs(node, dict);
        return dict[node];
    }

    void dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &dict) {
        if (node == nullptr) {
            return;
        }
        
        if (dict.find(node) == dict.end()) {
            dict[node] = new UndirectedGraphNode(node->label);
            for (const auto& neigh : node->neighbors) {
                dfs(neigh, dict);
                dict[node]->neighbors.emplace_back(dict[neigh]);
            }
        }
    }
};
