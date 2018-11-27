class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return "0"

        rt = ""
        if (numerator < 0) ^ (denominator < 0):
            rt += '-'
        #如果是C 则需要考虑INT_MIN的绝对值溢出等问题...
        num = abs(numerator)
        den = abs(denominator)
        rt += str(num // den)
        rem = (num % den) * 10
        if rem == 0:
            return rt

        rt += '.'
        remainders = {}
        while rem != 0:
            if rem in remainders:
                index = remainders[rem]
                rt = rt[:index] + '(' + rt[index:] + ')'
                return rt
            remainders[rem] = len(rt)
            rt += str(rem // den)
            rem = (rem % den) * 10
        return rt


s = Solution()
print(s.fractionToDecimal(1,99))
print(s.fractionToDecimal(4,9))
print(s.fractionToDecimal(0,3))
print(s.fractionToDecimal(9,3))
print(s.fractionToDecimal(5,2))
print(s.fractionToDecimal(5,7))
print(s.fractionToDecimal(4,333))
print(s.fractionToDecimal(40,333))
print(s.fractionToDecimal(400,333))
print(s.fractionToDecimal(-9,3))
print(s.fractionToDecimal(9,-3))
print(s.fractionToDecimal(-9,-3))
