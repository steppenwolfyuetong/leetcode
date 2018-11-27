class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cache = set()
        while n != 1:
            n = sum([int(i) ** 2 for i in str(n)])
            if n in cache:
                return False
            else:
                cache.add(n)
        return True

s = Solution()
print(s.isHappy(19))

