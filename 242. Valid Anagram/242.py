class Solution(object):
    def isAnagram1(self, s, t):
        return sorted(s) == sorted(t)

    def isAnagram2(self, s, t):
        table = {}
        for letter in s:
            if letter in table:
                table[letter] += 1
            else:
                table[letter] = 1
        for letter in t:
            if letter not in table:
                return False
            else:
                table[letter] -= 1
        for key in table:
            if table[key] != 0:
                return False
        return True

s = Solution()
print(s.isAnagram1("rat","cat"))
print(s.isAnagram1("anagram","nagaram"))
print(s.isAnagram2("rat","cat"))
print(s.isAnagram2("anagram","nagaram"))
