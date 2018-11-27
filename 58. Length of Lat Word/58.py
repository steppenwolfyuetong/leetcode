class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        count = 0
        last = 0
        for i in range(len(s)):
            if s[i] != ' ':
                count += 1
                continue
            if s[i] == ' ' and count != 0:
                last = count
                count = 0
        if count:
            return count
        else:
            return last

print(Solution.lengthOfLastWord(Solution,"Hello world cao  "))
print(Solution.lengthOfLastWord(Solution,"a"))
