class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        rt = 0
        for i in range(len(s)):
            rt = rt * 26 + ord(s[i]) - ord('A') + 1
        return rt

s = Solution()
print(s.titleToNumber("AZ"))
