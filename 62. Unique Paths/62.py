class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    # 直接dfs TLE 加入缓存 时间复杂度O(n^4)
    """
    def uniquePaths(self, m, n):
        if m < 1 or n < 1:
            return 0
        if m == n == 1:
            return 1
        return self.uniquePaths(m-1,n) + self.uniquePaths(m,n-1)
    """
    # dfs + cache
    def uniquePaths(self, m, n):
        self.cache = [[0 for j in range(n+1)] for i in range(m+1)]
        return self.dfs(m,n)

    def dfs(self, m, n):
        if m < 1 or n < 1:
            return 0
        if m == n == 1:
            return 1
        if self.cache[m-1][n]:
            up = self.cache[m-1][n]
        else:
            up = self.cache[m-1][n] = self.dfs(m-1,n)
        if self.cache[m][n-1]:
            left = self.cache[m][n-1]
        else:
            left = self.cache[m][n-1] = self.dfs(m,n-1)
        return up + left
    # dp also works

s = Solution()
print(s.uniquePaths(23,12))
