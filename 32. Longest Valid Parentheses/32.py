class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        dp = [0] * (len(s)+1)           # dp[i]: longest length of s[:i]
        count = 0                       # count is the num of unmatched '('
        for i in range(1,len(dp)):
            if s[i-1] == '(':
                count += 1
            else:
                if count:
                    count -= 1
                    dp[i] = 2
                    if i - 2 >= 0 and s[i-2] == ')':
                        dp[i] += dp[i-1]
                    dp[i] += dp[i-dp[i]]
        print(dp)
        return max(dp)

Solution.longestValidParentheses(Solution,'(()())())')
