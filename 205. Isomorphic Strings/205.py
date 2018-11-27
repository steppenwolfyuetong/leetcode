class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        #只用一个map
        table = {}
        for i in range(len(s)):
            if s[i] not in table:
                for key in table:
                    if table[key] == t[i]:
                        return False
                table[s[i]] = t[i]
            elif table[s[i]] != t[i]:
                return False
        return True

    def isIsomorphic1(self, s, t):
        #用两个map 效率更高
        tableS = {}
        tableT = {}
        for i in range(len(s)):
            if s[i] not in tableS and t[i] not in tableT:
                tableS[s[i]] = t[i]
                tableT[t[i]] = s[i]
            else:
                try:
                    if tableS[s[i]] != t[i] or tableT[t[i]] != s[i]:
                        return False
                except KeyError as e:
                    return False
        return True

s = Solution()
print(s.isIsomorphic1("egg","add"))
print(s.isIsomorphic1("foo","bar"))
print(s.isIsomorphic1("paper","title"))
print(s.isIsomorphic1("ab","aa"))
