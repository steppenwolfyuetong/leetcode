class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < = 0:
            return 0
        ugly = [1]
        p2, p3, p5 = 0, 0, 0
        while len(ugly) < n:
            ugly.append(min(ugly[p2] * 2, ugly[p3] * 3, ugly[p5] * 5))
            if ugly[-1] == ugly[p2] * 2:
                p2 += 1
            if ugly[-1] == ugly[p3] * 3:
                p3 += 1
            if ugly[-1] == ugly[p5] * 5:
                p5 += 1
        return ugly[n - 1]

s = Solution()
print(s.nthUglyNumber(10))
