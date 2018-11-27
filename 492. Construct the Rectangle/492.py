import math

class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        mid = int(math.sqrt(area))
        while area % mid != 0:
            mid -= 1

        return [area // mid, mid]

if __name__ == "__main__":
    s = Solution()
    print(s.constructRectangle(12))

