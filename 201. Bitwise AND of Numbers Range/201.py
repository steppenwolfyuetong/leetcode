class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # Consider the bits from low to high.
        # if n > m, the lowest bit will be 0,
        # and then we could transfer the problem to sub-problem: rangeBitwiseAnd(m>>1, n>>1).
        shift = 0
        while m != n:
            m >>= 1
            n >>= 1
            shift += 1
        return m << shift

s = Solution()
print(s.rangeBitwiseAnd(5,7))
