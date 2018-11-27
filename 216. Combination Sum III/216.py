"""
Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.
"""
class Solution:
    # @param {integer} k
    # @param {integer} n
    # @return {integer[][]}
    def combinationSum3(self, k, n):
        self.result = []
        self.path = []
        self.dfs(k, n, 1)
        return self.result

    def dfs(self, k, gap, start):
        if len(self.path) == k:
            if gap == 0:
                self.result.append(self.path[:])
            return
        for i in range(start,10):
            if gap < i:
                return
            self.path.append(i)
            self.dfs(k, gap - i, i + 1)
            self.path.pop()

s = Solution()
print(s.combinationSum3(3,7))
print(s.combinationSum3(3,3))
