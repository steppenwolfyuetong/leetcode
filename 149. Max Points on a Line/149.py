class Point(object):
    def __init__(self, a = 0, b = 0):
        self.x = a
        self.y = b

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        if len(points) < 3:
            return len(points)
        result = 0
        d = {}                      #以斜率为key,共线点数量为value
        for i in range(len(points)):
            d.clear()
            overlap = 0
            curmax = 0
            for j in range(i+1,len(points)):
                dx = points[j].x - points[i].x
                dy = points[j].y - points[i].y
                if dx == 0 and dy == 0:
                    overlap += 1
                    continue
                slope = dy * 1.0 / dx if dx != 0 else "infinity"
                if slope in d:
                    d[slope] += 1
                else:
                    d[slope] = 1
                curmax = max(curmax,d[slope])
            result = max(result,curmax + overlap + 1)
        return result

s = Solution()
points = [Point(84,250),Point(0,0),Point(1,0),Point(0,-70),Point(0,-70),Point(1,-1),Point(21,10),Point(42,90),Point(-42,-230)]
print(s.maxPoints(points))
