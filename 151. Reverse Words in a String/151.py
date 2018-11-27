class Solution(object):
    def reverseWords(self,s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(reversed(s.split()))


string = " the sky is blue"
s = Solution()
print(s.reverseWords(string))

