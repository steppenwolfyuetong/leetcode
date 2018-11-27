class Solution:
    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solveSudoku(self, board):
        self.solve(board)

    def solve(self,board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for k in range(9):
                        board[i][j] = str(int('1') + k)
                        if self.isValid(board, i, j) and self.solve(board):
                            return True
                        board[i][j] = '.'
                    return False
        return True

    def isValid(self, board, x, y):
        for i in range(9):
            if i != x and board[i][y] == board[x][y]:
                return False
        for j in range(9):
            if j != y and board[x][j] == board[x][y]:
                return False
        for i in range(3 * (x // 3), 3 * (x // 3 + 1)):
            for j in range(3 * (y // 3), 3 * (y // 3 + 1)):
                if (i != x or j != y) and board[i][j] == board[x][y]:
                    return False
        return True

s = Solution()
mat = [ ['5','3','.','.','7','.','.','.','.'],
        ['6','.','.','1','9','5','.','.','.'],
        ['.','9','8','.','.','.','.','6','.'],
        ['8','.','.','.','6','.','.','.','3'],
        ['4','.','.','8','.','3','.','.','1'],
        ['7','.','.','.','2','.','.','.','6'],
        ['.','6','.','.','.','.','2','8','.'],
        ['.','.','.','4','1','9','.','.','5'],
        ['.','.','.','.','8','.','.','7','9'] ]
s.solveSudoku(mat)
print(mat)
