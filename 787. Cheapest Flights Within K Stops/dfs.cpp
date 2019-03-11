#include "../leetcode.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // map of {src -> vec<{dst, price}>}
        for (const auto& flight : flights) {
            dict_[flight[0]].emplace_back(flight[1], flight[2]);
        }
        visited_ = vector<bool>(n, false);

        int result = INT_MAX;
        dfs(src, dst, K, 0, result);
        return result == INT_MAX ? -1 : result;
    }

    void dfs(int src, int dst, int K, int price, int &result) {
        if (src == dst) {
            result = min(result, price);
            return;
        }
        if (K < 0) {
            return;
        }

        visited_[src] = true;
        vector<pair<int, int>> fly = dict_[src];
        for (int j = 0; j < fly.size(); j++) {
            if (visited_[fly[j].first]) {
                continue;
            }
            if (fly[j].second + price >= result) {
                continue;           // Important: prunning
            }
            dfs(fly[j].first, dst, K - 1, fly[j].second + price, result);
        }
        visited_[src] = false;
    }
private:
    unordered_map<int, vector<pair<int, int>>> dict_;
    vector<bool> visited_;                  // for pruning
};

int main() {
    Solution s;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << s.findCheapestPrice(3, flights, 0, 2, 0) << endl;
    cout << s.findCheapestPrice(3, flights, 0, 2, 1) << endl;
}
