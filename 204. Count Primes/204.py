class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        #Count the number of prime numbers less than a non-negative number, n.
        sieve = [0,0] + [1] * (n - 1)
        k = n ** 0.5
        for i in range(2,int(k) + 1):
            #找到下一个素数，用来筛选
            if sieve[i] == 0:
                continue
            #对于某个素数i 可以直接从i^2开始筛选 因为从i到i**2的其余合数已经被剔除
            for j in range(i*i,n,i):
                sieve[j] = 0
        rt = 0
        for i in range(2,n):
            if sieve[i]:
                rt += 1
        return rt

from pprint import pprint
s = Solution()
print(s.countPrimes(5))
