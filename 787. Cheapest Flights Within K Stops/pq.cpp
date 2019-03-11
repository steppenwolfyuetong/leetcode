#include "../leetcode.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> dict;
        for (const auto& flight : flights) {
            dict[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // min heap
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        pq.push({0, src, K + 1});
        while (!pq.empty()) {
            int price = get<0>(pq.top());
            int city = get<1>(pq.top());
            int count = get<2>(pq.top());
            pq.pop();

            if (city == dst) {
                return price;
            }

            if (count > 0) {
                vector<pair<int, int>> out = dict[city];
                for (const auto& fly : out) {
                    pq.push({price + fly.second, fly.first, count - 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << s.findCheapestPrice(3, flights, 0, 2, 1) << endl;
}
