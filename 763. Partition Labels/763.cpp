#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // same as 56. Merge Intervals
    vector<int> partitionLabels(string S) {
        //abaccbdeffed: abaccb deffed
        map<char, int> firstIndex, lastIndex;
        for (int i = 0; i < S.size(); i++) {
            if (!firstIndex.count(S[i])) {
                firstIndex[S[i]] = i;
            }
            lastIndex[S[i]] = i;
        }

        vector<pair<int, int>> intervals;
        for (const auto& first : firstIndex) {
            pair<int, int> p = {first.second, lastIndex[first.first]};
            insert(intervals, p);
        }

        vector<int> result;
        for (const auto& interval : intervals) {
            result.emplace_back(interval.second - interval.first + 1);
        }
        return result;
    }

    void insert(vector<pair<int, int>> &intervals, pair<int, int> newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end()) {
            if (it->first > newInterval.second) {
                intervals.insert(it, newInterval);
                return;
            } else if (it->second < newInterval.first) {
                it++;
            } else {
                // overlapping
                newInterval.first = min(it->first, newInterval.first);
                newInterval.second = max(it->second, newInterval.second);
                it = intervals.erase(it);
            }
        }
        intervals.insert(it, newInterval);
    }
};
