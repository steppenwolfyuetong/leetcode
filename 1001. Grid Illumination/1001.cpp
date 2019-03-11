#include "../leetcode.h"

class Solution {
public:
    // 1 <= N <= 10 ^ 9, so can't load into memory
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int, int>> light;
        unordered_map<int, int> hor, ver, diag, adiag;
        for (const auto& lamp : lamps) {            // save how many lamps can light this row/col/diag/anti-diag.
            auto x = lamp[0], y = lamp[1];
            hor[x]++; ver[y]++; diag[x - y]++; adiag[x + y]++;
            light.insert({x, y});
        }

        vector<int> result;
        for (const auto& query : queries) {
            auto x = query[0], y = query[1];
            if (hor[x] || ver[y] || diag[x - y] || adiag[x + y]) {      // check if any lamp can list on the [x, y]
                result.emplace_back(1);
                for (int xxx = x - 1; xxx <= x + 1; xxx++) {
                    for (int yyy = y - 1; yyy <= y + 1; yyy++) {
                        if (light.erase({xxx, yyy})) {                  // turn off adjacent light
                            hor[xxx]--; ver[yyy]--; diag[xxx - yyy]--; adiag[xxx + yyy]--;
                        }
                    }
                }
            } else {
                result.emplace_back(0);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> lamps = {{0,0},{4,4}};
    vector<vector<int>> queries = {{1,1},{1,1}};
    s.gridIllumination(5, lamps, queries);
}
