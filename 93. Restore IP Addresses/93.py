class Solution:
    # @param {string} s
    # @return {string[]}
    def restoreIpAddresses(self, s):
        self.result = []
        self.path = []
        self.dfs(s, 0, 0)
        return self.result

    def dfs(self, s, index, count):
        print(self.path, index, count)
        if index == len(s) and count == 4:
            self.result.append('.'.join(self.path))
            return
        # 剪枝
        if len(s) - index > (4 - count) * 3:
            return
        if len(s) - index < 4 - count:
            return
        for i in range(index, index + 3):
            part = s[index : i+1]
            if int(part) < 256:
                self.path.append(part)
                self.dfs(s, i + 1, count + 1)
                self.path.pop()
            if part == '0':
                break

s = Solution()
print(s.restoreIpAddresses("25525511135"))
