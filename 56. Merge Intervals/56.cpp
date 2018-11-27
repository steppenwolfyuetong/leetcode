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
        vector<Interval> result;
        for(int i = 0; i < intervals.size(); i++)
            insert(result, intervals[i]);
        return result;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end())
        {
            if(newInterval.end < it->start)
            {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if(newInterval.start > it->end)
            {
                it++;
                continue;
            }
            else
            {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
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
