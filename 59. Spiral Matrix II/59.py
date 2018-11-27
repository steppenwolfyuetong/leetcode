import pprint
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n == 0:
            return []
        matrix = [[0 for i in range(n)] for i in range(n)]
        x1, x2 = 0, len(matrix[0]) - 1
        y1, y2 = 0, len(matrix) - 1
        num = 1
        while(1):
            for j in range(x1,x2+1):
                matrix[y1][j] = num
                num += 1
            y1 += 1
            if y1 > y2:
                break
            for i in range(y1,y2+1):
                matrix[i][x2] = num
                num += 1
            x2 -= 1
            if x1 > x2:
                break
            for j in range(x2,x1-1,-1):
                matrix[y2][j] = num
                num += 1
            y2 -= 1
            if y1 > y2:
                break
            for i in range(y2,y1-1,-1):
                matrix[i][x1] = num
                num += 1
            x1 += 1
            if x1 > x2:
                break
        return matrix

s= Solution()
pprint.pprint(s.generateMatrix(3))
