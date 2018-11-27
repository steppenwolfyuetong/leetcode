"""
C(n,k) = C(n-1,k-1) + C(n-1,k)
"""

class Solution:
    # @param {integer} n
    # @param {integer} k
    # @return {integer[][]}
    def combine(self, n, k):
        if k == 1:
            return [[i] for i in range(1,n+1)]
        elif k == n:
            return [[i for i in range(1,n+1)]]
        else:
            result = []
            result.extend(self.combine(n-1,k))
            part = self.combine(n-1,k-1)
            for path in part:
                path.append(n)
            result.extend(part)
            return result

s = Solution()
print(s.combine(4,2))

