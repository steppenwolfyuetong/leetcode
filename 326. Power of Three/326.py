class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        while n % 3 == 0:
            n //= 3
        return n == 1

if __name__ == "__main__":
    s = Solution()
    print(s.isPowerOfThree(80))

