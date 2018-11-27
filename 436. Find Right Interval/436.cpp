/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/*
 * none of these intervals have the same start point
 */

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> table;        
        vector<int> rt;
        for(int i = 0; i < intervals.size(); i++)
        {
            table[intervals[i].start] = i;
        }

        for(Interval interval : intervals)
        {
            // map有序
            // iter指向第一个满足iter->start >= iterval.end的元素 
            map<int, int>::iterator iter = table.lower_bound(interval.end);
            if(iter == table.end())
                rt.push_back(-1);
            else
                rt.push_back(iter->second);
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<Interval> intervals;
    intervals.push_back(Interval(3,4));
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(1,2));

    vector<int> rt = s->findRightInterval(intervals);
    for(int i = 0; i < rt.size(); i++)
        cout << rt[i] << ' ';
    cout << endl;

    return 0;
}
