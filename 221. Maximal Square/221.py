class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # dp[i][j] 表示以(i,j)为右下角的最大正方形面积
        if len(matrix) == 0:
            return 0

        rt = 0
        m = len(matrix)
        n = len(matrix[0])
        dp = [ [0 for j in range(n)] for i in range(m)]

        for i in range(m):
            dp[i][0] = 1 if matrix[i][0] == '1' else 0
            rt = max(dp[i][0],rt)
        for j in range(n):
            dp[0][j] = 1 if matrix[0][j] == '1' else 0
            rt = max(dp[0][j],rt)

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + 1
                    rt = max(dp[i][j],rt)
        return rt * rt

s = Solution()
matrix = [['1','0','1','0','0'],
          ['1','0','1','1','1'],
          ['1','1','1','1','1'],
          ['1','0','0','1','0']]
print(s.maximalSquare(matrix))
