class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        if len(timeSeries) == 0:
            return 0

        if len(timeSeries) == 1:
            return duration

        rt = 0
        for i in range(1, len(timeSeries)):
            if timeSeries[i] - timeSeries[i - 1] > duration:
                rt += duration
            else:
                rt += timeSeries[i] - timeSeries[i-1]
        rt += duration          # last attack
        return rt

if __name__ == "__main__":
    timeSeries = [1,4]
    duration = 2
    s = Solution()
    print(s.findPoisonedDuration(timeSeries, duration))


