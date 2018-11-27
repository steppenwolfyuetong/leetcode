class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        d = 1
        while x // d >= 10:
            d *= 10
        while x > 0:
            q = x // d
            r = x % 10
            if q != r:
                return False
            x = x % d // 10
            d = d // 100
        return True

s = Solution()
print(s.isPalindrome(12321))
print(s.isPalindrome(123321))
print(s.isPalindrome(123))
