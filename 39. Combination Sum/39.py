class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum(self, candidates, target):
        candidates.sort()
        self.result = []
        self.path = []
        self.dfs(candidates, target , 0)
        return self.result

    def dfs(self, num, gap, index):
        # 终止条件
        if gap == 0:
            self.result.append(self.path[:])
            print("!")
            return
        for i in range(index,len(num)):
            # 剪枝
            if gap < num[i]:
                return
            self.path.append(num[i])
            # 可以重复取相同元素
            self.dfs(num, gap - num[i], i)
            self.path.pop()

s = Solution()
print(s.combinationSum([2,6,3,7],7))
