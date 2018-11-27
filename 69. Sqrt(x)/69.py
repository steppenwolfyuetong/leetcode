class Solution:
    # @param {integer} x
    # @return {integer}
    def mySqrt(self, x):
        a = 1
        b = x // 2
        if x < 2:
            return x
        print(a,b)
        while a <= b:
            mid = (a + b) // 2
            if mid * mid > x:
                b = mid - 1
            elif mid * mid < x:
                a = mid + 1
                last = mid
            else:
                return mid
        return last

s = Solution()
print(s.mySqrt(5))
