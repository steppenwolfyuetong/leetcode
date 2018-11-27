# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

import bisect

class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        table = sorted((interval.start, i) for i, interval in enumerate(intervals))

        rt = []
        for interval in intervals:
            index = bisect.bisect_left(table, (interval.end,))
            if index < len(table):
                rt.append(table[index][1])
            else:
                rt.append(-1)
        return rt

if __name__ == "__main__":
    s = Solution();
    intervals = []
    intervals.append(Interval(3,4))
    intervals.append(Interval(2,3))
    intervals.append(Interval(1,2))

    print(s.findRightInterval(intervals))

