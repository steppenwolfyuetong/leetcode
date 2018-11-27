class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        #因数分解 实际上是取决于5的个数
        #求因数5的方法为 n/5 + n/25 + n/125 + ...
        rt = 0
        while n:
            rt += n // 5
            n //= 5
        return rt

s = Solution()
print(s.trailingZeroes(654))
print(s.trailingZeroes(665))
print(s.trailingZeroes(676))

