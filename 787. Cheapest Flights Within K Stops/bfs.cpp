/*
The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
*/

#include "../leetcode.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // map of {src -> vec<{dst, price}>}
        unordered_map<int, vector<pair<int, int>>> dict;
        for (const auto& flight : flights) {
            dict[flight[0]].emplace_back(flight[1], flight[2]);
        }

        int result = INT_MAX, count = 0;    // count of stop
        queue<pair<int, int>> q;            // queue of {current city, current price}
        q.push({src, 0});                   // init state

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int city = q.front().first, price = q.front().second;
                q.pop();

                if (city == dst) {
                    result = min(result, price);
                }

                vector<pair<int, int>> fly = dict[city];
                for (int j = 0; j < fly.size(); j++) {
                    if (fly[j].second + price >= result) {
                        continue;           // Important: prunning
                    }
                    q.push({fly[j].first, fly[j].second + price});
                }
            }
            if (count++ > K) {
                break;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << s.findCheapestPrice(3, flights, 0, 2, 1) << endl;
}
