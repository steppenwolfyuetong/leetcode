import pprint

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1)
        n = len(word2)
        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        dp[0][0] = 0
        for i in range(1,m+1):
            dp[i][0] = i
        for j in range(1,n+1):
            dp[0][j] = j
        for i in range(1,m+1):
            for j in range(1,n+1):
                # 判断word1的第i-1个字符 和 word2的第j-1个字符 是否一致
                if word1[i-1] == word2[j-1]:
                    # 一致则两个词的距离取决于之前的字符
                    dp[i][j] = dp[i-1][j-1]
                else:
                    # 替换
                    replace = dp[i-1][j-1] + 1
                    # 添加和删除本质上相同
                    insert = min(dp[i-1][j] + 1, dp[i][j-1] + 1)
                    dp[i][j] = min(replace,insert)
        pprint.pprint(dp)
        return dp[-1][-1]

s = Solution()
print(s.minDistance("str1c","str1"))
