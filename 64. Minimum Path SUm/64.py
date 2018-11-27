class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [[0 for j in range(len(grid[0]))] for i in range(len(grid))]
        dp[0][0] = grid[0][0]
        for i in range(1,len(grid)):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for j in range(1,len(grid[0])):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1,len(grid)):
            for j in range(1,len(grid[0])):
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j]
        return dp[-1][-1]

s = Solution()
print(s.minPathSum([[1,2,3],[4,5,6],[7,8,9]]))
