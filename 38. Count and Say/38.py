"""
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
"""

class Solution:
    def nextSay(self,say):
        say = list(say)
        result = []
        for i in range(len(say)):
            if len(result) and say[i] == result[-1]:
                result[-2] = str(int(result[-2]) + 1)
            else:
                result += ['1',say[i]]
        return ''.join(result)

    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        result = '1'
        n -= 1
        while n:
            result = self.nextSay(self,result)
            n -= 1
        return result



s = Solution()
print(s.countAndSay(6))

