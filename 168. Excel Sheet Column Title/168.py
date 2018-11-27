class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        letter = ['Z'] + [chr(65 + i) for i in range(25)]
        rt = ""
        while n != 0:
            rt = letter[n % 26] + rt
            n = (n - 1) // 26           #A = 1，下标不是从0开始，需要减一 否则当输入26时 结果即为AZ
        return rt

s = Solution()
for i in range(1,53):
    print(s.convertToTitle(i))

