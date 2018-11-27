class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                count = 0
                # 遍历九宫格
                for x in range(max(0,i-1),min(m,i+2)):
                    for y in range(max(0,j-1),min(n,j+2)):
                        count += board[x][y] & 1
                # 去除自身
                count -= board[i][j] & 1

                # 将下一个状态信息存在高一位
                if board[i][j] and (count == 2 or count == 3):
                    board[i][j] |= 2
                if not board[i][j] and count == 3:
                    board[i][j] |= 2

        # 将状态信息右移一位 用新的代替
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1

from pprint import pprint
s = Solution()
board = [[1,1,1],
         [0,1,0],
         [0,1,0]]
s.gameOfLife(board)
pprint(board)

