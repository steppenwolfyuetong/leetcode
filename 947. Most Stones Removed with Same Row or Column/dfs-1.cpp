#include <set>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    // change from vector to pair, 2192ms
    int removeStones(vector<vector<int>>& stones) {
        int islands = 0;
        for (const auto& stone : stones) {
            if (!visited.count({stone[0], stone[1]})) {
                dfs(stone[0], stone[1], stones);
                islands++;
            }
        }
        return stones.size() - islands;
    }

    void dfs(int x, int y, vector<vector<int>> &stones) {
        visited.insert({x, y});                     // 不能使用emplace(x, y), 会调用vector<int>(x, y)
        for (const auto& stone : stones) {
            if (!visited.count({stone[0], stone[1]})) {
                if (stone[0] == x || stone[1] == y) {
                    dfs(stone[0], stone[1], stones);
                }
            }
        }
    }
private:
    set<pair<int, int>> visited;
};

int main() {
    Solution s;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << s.removeStones(stones) << endl;
    return 0;
}
