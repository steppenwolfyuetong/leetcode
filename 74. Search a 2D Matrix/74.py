class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        n = len(matrix[0])
        begin = 0
        end = m * n
        while(begin < end):
            mid = (begin + end) // 2
            i = mid // n
            j = mid % n
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                begin = mid + 1
            else:
                end = mid
        return False

#mat = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
mat = [[1,1]]
print(Solution.searchMatrix(Solution,mat,0))
