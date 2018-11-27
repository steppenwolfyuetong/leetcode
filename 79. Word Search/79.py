class Solution:
    # @param {character[][]} board
    # @param {string} word
    # @return {boolean}
    def exist(self, board, word):
        m = len(board)
        n = len(board[0])
        self.board = board[:]
        self.word = word[:]
        self.visited = [ [False for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                if self.dfs(0, i, j):
                    return True
        return False

    def dfs(self, index, x, y):
        if index == len(self.word):
            return True
        if x < 0 or y < 0 or x >= len(self.board) or y >= len(self.board[0]):
            return False
        if self.visited[x][y]:
            return False
        if self.board[x][y] != self.word[index]:
            return False
        self.visited[x][y] = True
        result = self.dfs(index + 1, x - 1, y) or self.dfs(index + 1, x + 1, y) or self.dfs(index + 1, x, y -1) or self.dfs(index + 1, x, y + 1)
        self.visited[x][y] = False
        return result

s = Solution()
board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
word = "ABCB"
print(s.exist(board,word))

