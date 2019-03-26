#include "../leetcode.h"

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) {
            return {};
        }
        return helper(buildings, 0, buildings.size() - 1);
    }

    // divide and conquer
    vector<pair<int, int>> helper(vector<vector<int>>& buildings, int left, int right) {
        if (left == right) {
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
        } else {
            int mid = (left + right) / 2;
            vector<pair<int, int>> p = helper(buildings, left, mid);
            vector<pair<int, int>> q = helper(buildings, mid + 1, right);
            return merge(p, q);
        }
    }

    vector<pair<int, int>> merge(vector<pair<int, int>> &s1, vector<pair<int, int>> &s2) {
        vector<pair<int, int>> result;
        int i = 0, j = 0, h1 = 0, h2 = 0;
        while (i < s1.size() && j < s2.size()) {
            int x = 0, y = 0;                   // (x, y) is next critical point
            if (s1[i].first < s2[j].first) {
                x = s1[i].first;
                h1 = s1[i].second;
                i++;
            } else if (s1[i].first > s2[j].first) {
                x = s2[j].first;
                h2 = s2[j].second;
                j++;
            } else {
                x = s1[i].first;
                h1 = s1[i].second;
                h2 = s2[j].second;
                i++;
                j++;
            }
            y = max(h1, h2);
            if (result.empty() || result.back().second != y) {
                result.emplace_back(x, y);
            }
        }

        while (i < s1.size()) {
            result.emplace_back(s1[i++]);
        }
        while (j < s2.size()) {
            result.emplace_back(s2[j++]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<pair<int, int>> result = s.getSkyline(buildings);
    for (const auto& xy : result) {
        cout << xy.first << "," << xy.second << endl;
    }
    cout << endl;

    buildings = {{1,2,1},{1,2,2}};
    result = s.getSkyline(buildings);
    for (const auto& xy : result) {
        cout << xy.first << "," << xy.second << endl;
    }
    cout << endl;
}
