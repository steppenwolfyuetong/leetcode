#include<vector>
#include<iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return vector<Interval>();
        }
        sort(intervals.begin(), intervals.end(), cmp());

        vector<Interval> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end < intervals[i].start) {
                result.emplace_back(intervals[i]);
            } else {
                result.back().end = max(result.back().end, intervals[i].end);
            }
        }
        return result;
    }

private:
    struct cmp {
        bool operator()(const Interval &a, const Interval &b) {
            return a.start < b.start;
        }
    };
};

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));
	Solution *s = new Solution;
    vector<Interval> result = s->merge(intervals);
    for(int i = 0; i < result.size(); i++)
        cout<<result[i].start<<' '<<result[i].end<<endl;
}
