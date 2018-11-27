class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        letter = ['I','V','X','L','C','D','M','','']
        i = 0
        result = ''
        while num != 0:
            digit = num % 10
            if 0 <= digit < 4:
                result = letter[i] * digit + result
            elif digit == 4:
                result = letter[i] + letter[i+1] + result
            elif 5 <= digit < 9:
                result = letter[i+1] + letter[i] * (digit - 5) + result
            else:
                result = letter[i] + letter[i+2] + result
            num //= 10
            i += 2
        return result

print(Solution.intToRoman(Solution.intToRoman,3999))
