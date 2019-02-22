class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum2(self, candidates, target):
        candidates.sort()
        self.result = []
        self.path = []
        self.dfs(candidates, target, 0)
        return self.result

    def dfs(self, num, gap, index):
        if gap == 0:
            self.result.append(self.path[:])
            return
        for i in range(index, len(num)):
            if i > index and num[i] == num[i-1]:
                continue
            if gap < num[i]:
                return
            pre = num[i]
            self.path.append(num[i])
            self.dfs(num, gap - num[i], i + 1)
            self.path.pop()

s = Solution()
print(s.combinationSum2([10,1,2,7,6,1,5], 8))

