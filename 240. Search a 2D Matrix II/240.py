class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    
    # O(m*logn)
    def searchMatrix(self, matrix, target):
        for i in range(len(matrix)):
            if matrix[i][0] <= target:
                if self.searchRow(matrix[i], target):
                    return True
        return False

    def searchRow(self, row, target):
        begin = 0
        end = len(row)
        while(begin < end):
            mid = (begin + end) // 2
            if row[mid] == target:
                return True
            elif row[mid] < target:
                begin = mid + 1
            else:
                end = mid
        return False
    
    """
    # O(m+n)
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        n = len(matrix[0])
        i = 0
        j = n - 1
        while i < m and j > -1:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1
        return False
    """

mat = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
s = Solution()
print(s.searchMatrix(mat, 25))
