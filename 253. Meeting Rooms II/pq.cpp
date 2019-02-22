
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
};

bool cmp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

class Solution {  
public:  
/*
使用最小堆来解题的方法，这种方法先把所有的时间区间按照起始时间排序，然后新建一个最小堆用来保存当前在开的会的结束时间，
开始遍历时间区间，如果堆不为空，且首元素小于等于当前区间的起始时间，我们去掉堆中的首元素，
把当前区间的结束时间压入堆，由于最小堆是小的在前面，那么假如首元素小于等于起始时间，
说明上一个会议已经结束，可以用该会议室开始下一个会议了，所以不用分配新的会议室，
遍历完成后堆中元素的个数即为需要的会议室的个数，参见代码如下；
*/
    int minMeetingRooms(vector<Interval>& intervals) {  
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto meet : intervals)
        {
            if(!pq.empty() && pq.top() <= meet.start)
                pq.pop();
            pq.push(meet.end);
        }
        return pq.size();
    }  
};  

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(0,30));
    intervals.push_back(Interval(5,10));
    intervals.push_back(Interval(15,20));
    
    Solution s;
    cout << s.minMeetingRooms(intervals) << endl;
    return 0;
}
