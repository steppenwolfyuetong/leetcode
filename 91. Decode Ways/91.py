class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0 or s[0] == '0':
            return 0
        dp = [0 for i in range(len(s)+1)]
        dp[0] = 1
        for i in range(1,len(s)+1):
            if s[i-1] == '0':
                if s[i-2] != '1' and s[i-2] != '2':
                    return 0
                else:
                    dp[i] = dp[i-2]
            else:
                if i >= 2 and 11 <= int(s[i-2:i]) <= 26:
                    dp[i] = dp[i-2] + dp[i-1]
                else:
                    dp[i] = dp[i-1]
        print(dp)
        return dp[-1]

s = Solution()
print(s.numDecodings("12345"))
