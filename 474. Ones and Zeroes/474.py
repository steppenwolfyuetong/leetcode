class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """

        """
        dp[i][j]: the maximum number of strings that you can form with given i 0s and j 1s.
        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        dp[0][0] = 0
        """
        dp = [[0 for j in range(n + 1)] for i in range(m + 1)]
        for string in strs:
            zeros = string.count('0')
            ones = string.count('1')
            # 逆序 保证是上一次的结果
            # 否则需要用dp[k][m][n]来保存结果 k为数组大小
            for i in range(m, zeros - 1, -1):
                for j in range(n, ones - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        return dp[m][n]

if __name__ == "__main__":
    # strs = ["10", "0001", "111001", "1", "0"]
    # m = 5
    # n = 3
    strs = ["0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"]
    m = 9
    n = 80
    s = Solution()
    print(s.findMaxForm(strs, m, n))





"""
Example 1:

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”


Example 2:

Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
"""


