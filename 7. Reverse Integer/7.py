class Solution(object):
    def reverse(self, x):
        if x < 0: return -self.reverse(-x);
        result = 0;
        while x > 0:
            result = result * 10 + x % 10;
            x = x / 10;
        return 0 if result > 0x7FFFFFFF else result

s = Solution()
print(s.reverse(-10100))
