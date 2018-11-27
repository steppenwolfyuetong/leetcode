class Solution:
    # @param {string} s1
    # @param {string} s2
    # @param {string} s3
    # @return {boolean}
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        if len(s1) == len(s2) == len(s3) == 0:
            return True
        dp = [[False for j in range(len(s2)+1)] for i in range(len(s1)+1)]
        # 初始化
        for i in range(1,len(s1)+1):
            if s1[i-1] == s3[i-1]:
                dp[i][0] = True
            else:
                break
        for j in range(1,len(s2)+1):
            if s2[j-1] == s3[j-1]:
                dp[0][j] = True
            else:
                break
        
        for i in range(1,len(s1)+1):
            for j in range(1,len(s2)+1): 
                if ((s1[i-1] == s3[i+j-1]) and dp[i-1][j]) \
                or ((s2[j-1] == s3[i+j-1]) and dp[i][j-1]):
                    dp[i][j] = True
        return dp[-1][-1]
    
print(Solution.isInterleave(Solution.isInterleave,"","",""))