"""
Definition of dp[i][j]: minimum number of money to guarantee win for subproblem [i, j].
Target: dp[1][n]
Corner case: dp[i][i] = 0 (because the only element must be correct)
Equation: We can choose k (i<=k<=j) as our guess, and pay price k.
          After our guess, the problem is divided into two subproblems.
          Notice we do not need to pay the money for both subproblems.
          We only need to pay the worst case (because the system will tell us which side we should go) to guarantee win.
          So dp[i][j] = min (i<=k<=j) { k + max(dp[i][k-1], dp[k+1][j]) }
"""

import sys

class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0 for j in range(n+1)] for i in range(n+1)]
        # iterate the lengths of the intervals since the calculations of longer intervals rely on shorter ones
        for length in range(2, n+1):
            # iterate all the intervals with length l, the start of which is startPos.
            # the interval will be [startPos, startPos + length - 1]
            for startPos in range(1, n - length + 2):
                endPos = startPos + length - 1
                curMin = 2 ** 31 - 1
                # iterate all the first guess
                for cost in range(startPos + 1, endPos):
                    temp = cost + max(dp[startPos][cost-1], dp[cost+1][endPos])
                    curMin = min(curMin, temp)

                if startPos + 1 == endPos:
                    dp[startPos][endPos] = startPos
                else:
                    dp[startPos][endPos] = curMin
        return dp[1][n]

if __name__ == "__main__":
    s = Solution()
    print(s.getMoneyAmount(3))
    print(s.getMoneyAmount(8))
