# T = O(logn)
# x^n = x^(n/2) * x^(n/2) * x^(n%2)
class Solution:
    # @param {float} x
    # @param {integer} n
    # @return {float}
    def myPow(self, x, n):
        if n < 0:
            return 1 / self.power(x, -n)
        else:
            return self.power(x, n)

    def power(self, x, n):
        if n == 0:
            return 1
        half = self.power(x, n // 2)
        if n % 2 == 0:
            return half * half
        else:
            return half * half * x

s = Solution()
print(s.myPow(2,149))
