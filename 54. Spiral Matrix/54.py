class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = []
        if len(matrix) == 0:
            return result
        x1, x2 = 0, len(matrix[0]) - 1
        y1, y2 = 0, len(matrix) - 1
        while(1):
            for j in range(x1,x2+1):
                result.append(matrix[y1][j])
            y1 += 1
            if y1 > y2:
                break
            for i in range(y1,y2+1):
                result.append(matrix[i][x2])
            x2 -= 1
            if x1 > x2:
                break
            for j in range(x2,x1-1,-1):
                result.append(matrix[y2][j])
            y2 -= 1
            if y1 > y2:
                break
            for i in range(y2,y1-1,-1):
                result.append(matrix[i][x1])
            x1 += 1
            if x1 > x2:
                break
        return result

s = Solution()
mat = [[1,2,3],[4,5,6],[7,8,9]]
print(s.spiralOrder(mat))
