class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        letter = ['I','V','X','L','C','D','M']
        number = [1,5,10,50,100,500,1000]
        ans = 0
        for i in range(len(s)):
            cur = number[letter.index(s[i])]
            if i + 1 < len(s) and cur < number[letter.index(s[i+1])]:
                ans -= cur
            else:
                ans += cur
        return ans
        
print(Solution.romanToInt(Solution.romanToInt,"MMMCDLXXIV"))
