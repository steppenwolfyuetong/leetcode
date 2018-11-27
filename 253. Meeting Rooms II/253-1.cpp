/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/


/*
Definition for an interval.
class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
};

class Solution {  
public:  
/*
第二种方法是用两个一维数组来做，分别保存起始时间和结束时间，
然后各自排个序，我们定义结果变量res和结束时间指针endpos，
然后我们开始遍历，如果当前起始时间小于结束时间指针的时间，则结果自增1，
反之结束时间指针自增1，这样我们可以找出重叠的时间段，从而安排新的会议室
*/
    int minMeetingRooms(vector<Interval>& intervals) {  
        vector<int> start(intervals.size());  
        vector<int> end(intervals.size());  
        for(int i = 0; i < intervals.size(); i++) {  
            start[i] = intervals[i].start;  
            end[i] = intervals[i].end;  
        }  
        sort(start.begin(), start.end());  
        sort(end.begin(), end.end());  

        int room = 0, endIndex = 0;
        for(int i = 0; i < start.size(); i++)
        {
            if(start[i] < end[endIndex])
                room++;
            else
                endIndex++;
        }
        return room;  
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
