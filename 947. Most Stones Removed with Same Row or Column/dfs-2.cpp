#include <set>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    // change visited to vector<bool>(stones.size()), and use index to indicate whether the stone has been connected or not
    // 284ms
    int removeStones(vector<vector<int>>& stones) {
        visited = vector<bool>(stones.size(), false);
        int islands = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i]) {
                dfs(i, stones);
                islands++;
            }
        }
        return stones.size() - islands;
    }

    void dfs(int index, vector<vector<int>> &stones) {
        visited[index] = true;
        int x = stones[index][0], y = stones[index][1];
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] && (stones[i][0] == x || stones[i][1] == y)) {
                dfs(i, stones);
            }
        }
    }
private:
    vector<bool> visited;
};

int main() {
    Solution s;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << s.removeStones(stones) << endl;
    return 0;
}
