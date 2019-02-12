/*
Intuition:
We have 26 nodes in the graph. All "==" equations actually represent the connection in the graph.  
The connected nodes should be in the same color/union/set.

Then we check all inequations. Two inequal nodes should be in the different color/union/set.

Explanation:
We can solve this problem by DFS or Union Find.

Firt pass all "==" equations. Union equal letters together. Now we know which letters must equal to the others.

Second pass all "!=" inequations, check if there are any contradict happens.
*/

// Union-find: https://zxi.mytechroad.com/blog/data-structure/sp1-union-find-set/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (const auto& eq : equations) {
            if (eq[1] == '=') {
                parent[find(eq[0] - 'a')] = find(eq[3] - 'a');          // connect the root of two variable
            }
        }
        for (const auto& eq : equations) {
            if (eq[1] == '!') {
                if (find(eq[0] - 'a') == find(eq[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }

    // find the root of x
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);        // union find, modify the ancestor from leaf to root
        }
        return parent[x];
    }

    int parent[26];
};

