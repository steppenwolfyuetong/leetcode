from pprint import pprint

class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return
        self.acc = [[0 for j in range(len(matrix[0]) + 1)] for i in range(len(matrix) + 1)]
        for i in range(1,len(matrix)+1):
            for j in range(1,len(matrix[0])+1):
                self.acc[i][j] = self.acc[i][j-1] + self.acc[i-1][j] - self.acc[i-1][j-1] + matrix[i-1][j-1]

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.acc[row2+1][col2+1] - self.acc[row2+1][col1] - self.acc[row1][col2+1] + self.acc[row1][col1]

if __name__ == "__main__":
    matrix = [
            [3, 0, 1, 4, 2],
            [5, 6, 3, 2, 1],
            [1, 2, 0, 1, 5],
            [4, 1, 0, 1, 7],
            [1, 0, 3, 0, 5]
            ]
    s = NumMatrix(matrix)
    print(s.sumRegion(2,1,4,3))
    print(s.sumRegion(1,1,2,2))
    print(s.sumRegion(1,2,2,4))



# Your NumMatrix object will be instantiated and called as such:
# numMatrix = NumMatrix(matrix)
# numMatrix.sumRegion(0, 1, 2, 3)
# numMatrix.sumRegion(1, 2, 3, 4)
