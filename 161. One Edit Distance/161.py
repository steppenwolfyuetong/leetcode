
class Solution(object):
    def isOneEditDistance(self,s,t):
        """
        :type s,t: str
        :rtype: bool
        """
        if len(s) > len(t):
            s,t = t,s
        if len(t) - len(s) > 1:
            return False

        flag = False
        i ,j = 0,0
        while i < len(s):
            if s[i] != t[j]:
                if flag:
                    return False
                flag = True
                #delete or insert
                if len(s) < len(t):
                    i -= 1
            i += 1
            j += 1

        if flag:
            return True
        else:
            return True if len(s) + 1 == len(t) else False


s = Solution()
print(s.isOneEditDistance("abcdefg","abcdefg"))
print(s.isOneEditDistance("abcdefg","abc!efg"))
print(s.isOneEditDistance("abcdefg","abcdef"))
print(s.isOneEditDistance("abcdefg","abcdefgh"))
print(s.isOneEditDistance("abcefg","abcdefg"))
