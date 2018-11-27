class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        self.result = []
        self.generate(n, "", 0, 0)
        return self.result

    def generate(self, n, path, left, right):
        if left == n:
            path += ')' * (n - right)
            self.result.append(path)
            return
        self.generate(n, path + '(', left + 1, right)
        if left > right:
            self.generate(n, path + ')', left, right + 1)

s = Solution()
print(s.generateParenthesis(3))
