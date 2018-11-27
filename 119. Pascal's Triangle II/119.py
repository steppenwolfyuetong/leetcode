class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        result = []
        for i in range(0,rowIndex+1):
            # 第一个永远为1
            for j in range(i-1,0,-1):
                result[j] = result[j-1] + result[j]
                print(result)
            # 最后一个永远为1
            result.append(1)
            print(result)
        return result

s = Solution()
print(s.getRow(5))
