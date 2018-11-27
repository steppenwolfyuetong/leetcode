# TLE 相同算法 用C++就可以

class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(key = lambda x : (x[0],x[1]))        # 排序 以width和length为key

        dp = [1 for i in range(len(envelopes))]             # dp[i]表示当第i个信封为最大的那个信封时 能有多少层
        rt = 1

        for i in range(len(envelopes)):                     # 遍历第i个信封作为最大信封
            for j in range(i):                              # 遍历较小的信封
                if envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)           # 转移方程
            rt = max(rt, dp[i])
        return rt

s = Solution()
envelopes = [[5,4],[6,4],[6,7],[2,3]]
print(s.maxEnvelopes(envelopes))


