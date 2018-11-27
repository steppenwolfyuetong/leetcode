class Solution:
    # @param {integer} n
    # @return {integer[]}
    def grayCode(self,n):
        if n == 0:
            return [0]
        elif n == 1:
            return [0,1]
        else:
            result = Solution.grayCode(self,n-1)
            result.extend(reversed(Solution.grayCode(self,n-1)))
            for i in range(len(result)):
                if i < len(result) / 2:
                    result[i] |= 0
                else:
                    result[i] |= 1<<(n-1)
            return result

print(list(map(bin,Solution.grayCode(Solution.grayCode,4)))         )   