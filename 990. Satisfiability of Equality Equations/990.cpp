#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // build graph
        vector<vector<int>> neighbors(26);
        for (const auto& eq : equations) {
            if (eq[1] == '=') {
                neighbors[eq[0] - 'a'].emplace_back(eq[3] - 'a');
                neighbors[eq[3] - 'a'].emplace_back(eq[0] - 'a');
            }
        }

        // bfs the graph, save all the connected variable with same color
        vector<int> colors(26, -1);         // -1 means variable has not been colored
        int cur = 0;
        for (int i = 0; i < 26; i++) {
            if (colors[i] == -1) {
                queue<int> q;
                q.push(i);
                while (!q.empty()) {        // bfs
                    int index = q.front();
                    colors[index] = cur;
                    q.pop();
                    for (const auto& neigh : neighbors[index]) {
                        if (colors[neigh] == -1) {
                            q.push(neigh);
                        }
                    }
                }
                cur++;                      // change to next color
            }
        }

        for (const auto& eq : equations) {
            if (eq[1] == '!') {
                if(colors[eq[0] - 'a'] == colors[eq[3] - 'a']) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> equations = {"a==b","b!=a"};
    cout << s.equationsPossible(equations) << endl;
    equations = {"b==a","a==b"};
    cout << s.equationsPossible(equations) << endl;
    equations = {"a==b","b==c","a==c"};
    cout << s.equationsPossible(equations) << endl;
    equations = {"a==b","b!=c","c==a"};
    cout << s.equationsPossible(equations) << endl;
    equations = {"c==c","b==d","x!=z"};
    cout << s.equationsPossible(equations) << endl;
}
