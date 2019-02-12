/*
1) Check whether there is a node having two parents. 
    If so, store them as candidates A and B, and set the second edge invalid. 
2) Perform normal union find. 
    1. If the tree is now valid 
       simply return candidate B
    2. else if candidates not existing 
       we find a circle, return current edge; 
    3. else 
       remove candidate A instead of B.
*/

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent_ = vector<int>(n + 1, 0);
        vector<int> ans1, ans2;

        // step 1, check whether there is a node with two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent_[v] == 0) {
                parent_[v] = u;
            } else {                        // a node has two parent
                ans1 = {parent_[v], v};
                ans2 = edge;
                edge[1] = 0;                // invalid the second edge
            }
        }

        // step 2, union find
        for (int i = 0; i < parent_.size(); i++) {
            parent_[i] = i;
        }
        for (auto& edge : edges) {
            if (edge[1] == 0) {             // the invalid edge in step 1
                continue;
            }
            int u = edge[0], v = edge[1];
            int pu = find(u);
            if (pu == v) {                  // find a circle
                if (ans1.empty()) {
                    return edge;            // case 2, none of the nodes has two parent, remove the edge which forms the circle at last
                } else {
                    return ans1;            // case 3, one of the node has two parent, remove the edge in loop
                }
            }
            parent_[v] = pu;
        }
        return ans2;                        // case 1, no loop
    }
private:
    vector<int> parent_;

    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }
};
