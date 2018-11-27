"""
dp[i][j]: s的子串s[i,j]中 最长回文子串的长度 (j >= i)

初始条件:dp[i][i] = 1
状态转移:
    if s[i] == s[j]:
        dp[i][j] = dp[i+1][j-1] + 2
    else:                               # s[i] != s[j] 则取s[i][j-1]和s[i+1][j]中的较大者 即藏头和去尾中的最长回文子串
        dp[i][j] = max(dp[i][j-1], dp[i+1][j])
返回结果:dp[0][-1]

python  TLE...
C++     AC
"""

from pprint import pprint

class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        dp = [[0 for i in range(len(s))] for i in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = 1

        for i in range(len(s) - 1, -1, -1):
            for j in range(i + 1, len(s)):
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])
        # pprint(dp)
        return dp[0][-1]

if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindromeSubseq("babbab"))




