class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        count = {}
        for ch in t:
            if ch not in count:
                count[ch] = 1
            else:
                count[ch] += 1

        for ch in s:
            count[ch] -= 1

        for key in count:
            if count[key] != 0:
                return key
