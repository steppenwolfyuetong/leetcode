"""
1. If a mine ('M') is revealed, then the game is over - change it to 'X'.
2. If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
3. If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
4. Return the board when no more squares will be revealed.
"""




class Solution:
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        m = len(board)
        n = len(board[0])

        def neighbors(x, y):
            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    if (dx or dy) and 0 <= x + dx < m and 0 <= y + dy < n:
                        yield x + dx, y + dy


        stk = [click]
        while stk:
            x, y = stk.pop()
            if board[x][y] == 'M':
                board[x][y] = 'X'
            else:
                mines = sum(board[i][j] in "MX" for i, j in neighbors(x, y))
                if mines:
                    board[x][y] = str(mines)
                else:
                    board[x][y] = 'B'
                    for pair in neighbors(x, y):
                        if board[pair[0]][pair[1]] == 'E':
                            stk.append(pair)
        return board
