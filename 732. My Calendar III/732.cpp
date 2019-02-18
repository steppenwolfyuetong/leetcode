/*
Summarize
This is to find the maximum number of concurrent ongoing event at any time.

We can log the start & end of each event on the timeline, each start add a new ongoing event at that time, each end terminate an ongoing event. Then we can scan the timeline to figure out the maximum number of ongoing event at any time.

The most intuitive data structure for timeline would be array, but the time spot we have could be very sparse, so we can use sorted map to simulate the time line to save space.
*/
class MyCalendarThree {
    map<int, int> timeline;
public:
    int book(int s, int e) {
        timeline[s]++;      // 1 new event will be starting at [s]
        timeline[e]--;      // 1 new event will be ending at [e];
        int ongoing = 0, k = 0;
        for (pair<int, int> t : timeline)
            k = max(k, ongoing += t.second);
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
