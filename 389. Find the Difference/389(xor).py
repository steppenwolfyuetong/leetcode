class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        rt = 0
        for ch in s:
            rt ^= ord(ch)
        for ch in t:
            rt ^= ord(ch)
        return chr(rt)

    def findTheDifference(self, s, t):
        return chr(reduce(operator.xor, map(ord, s + t)))

    def findTheDifference(self, s, t):
        return list((collections.Counter(t) - collections.Counter(s)))[0]
