/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
#include <limits.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Interval {                               
    int start;                                  
    int end;                                    
    Interval() : start(0), end(0) {}            
    Interval(int s, int e) : start(s), end(e) {}
};

// sort by end in ascending order
bool intervalCmp(const Interval &a, const Interval &b)
{
    if(a.end != b.end)
        return a.end < b.end;
    else
        return a.start > b.start;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), intervalCmp);
        int curEnd = INT_MIN, rt = 0;
        for(Interval interval : intervals)
        {
            if(interval.start >= curEnd)
            {
                curEnd = interval.end;
            }
            else
            {
                // overlaped
                rt++;
            }
        }
        return rt;
    }

};

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,100));
    intervals.push_back(Interval(11,22));
    intervals.push_back(Interval(1,11));
    intervals.push_back(Interval(2,12));

    Solution *s = new Solution();
    cout << s->eraseOverlapIntervals(intervals) << endl;
}
