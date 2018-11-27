"""
若(x,y)为皇后
对于q == y 或 p + q == x + y 或 p - q == x - y
均无效
dfs
"""

class Solution:
    # @param {integer} n
    # @return {string[][]}
    def solveNQueens(self, n):
        self.result = []
        self.path = []
        self.dfs(n,[],[],[])
        return [ ['.' * queen[1] + 'Q' + '.' * (n - queen[1] -1) for queen in sol] for sol in self.result]

    def dfs(self, n, col, diag1, diag2):
        p = len(self.path)
        if p == n:
            self.result.append(self.path[:])
            return
        for q in range(n):
            if q not in col and p - q not in diag1 and p + q not in diag2:
                self.path.append([p,q])
                self.dfs(n, col + [q], diag1 + [p-q], diag2 + [p+q])
                self.path.pop()

s = Solution()
print(s.solveNQueens(4))
