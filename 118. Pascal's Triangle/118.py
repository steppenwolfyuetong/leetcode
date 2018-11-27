class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        line = []
        for i in range(1,numRows+1):
            for j in range(0,i):
                if j == 0:
                    line.append(1)
                elif j == i - 1:
                    line.append(1)
                else:
                    line.append(result[-1][j] + result[-1][j-1])
            result.append(line[:])
            line.clear()
            print(result,i)
        return result

s = Solution()
print(s.generate(5))
