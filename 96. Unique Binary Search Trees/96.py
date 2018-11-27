class Solution:
    # @param {integer} n
    # @return {integer}
    def numTrees(self, n):
        f = []
        # f(0) = 1  f(1) = 1
        f.append(1)
        f.append(1)
        for i in range(2,n+1):
            f.append(0)
            for k in range(i):
                f[-1] += f[k] * f[i-k-1]
        return f[n]

print(Solution.numTrees(Solution,4))
