class Solution:
    # @param {integer} n
    # @return {integer}
    def totalNQueens(self, n):
        self.result = 0
        self.path = []
        self.dfs(n,[],[],[])
        return self.result

    def dfs(self, n, col, diag1, diag2):
        p = len(self.path)
        if p == n:
            self.result += 1
            return
        for q in range(n):
            if q not in col and p - q not in diag1 and p + q not in diag2:
                self.path.append([p,q])
                self.dfs(n, col + [q], diag1 + [p-q], diag2 + [p+q])
                self.path.pop()

s = Solution()
print(s.totalNQueens(4))
