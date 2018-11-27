class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 出现偶数次的全部使用
        # 出现奇数次的除了其中一个字母可以全部使用 剩下的奇数次字母长度count需要减1
        table = {}
        for letter in s:
            if letter not in table:
                table[letter] = 1
            else:
                table[letter] += 1

        oddsCount = 0
        for key in table:
            if table[key] & 1:
                oddsCount += 1
        return len(s) - oddsCount + bool(oddsCount)

if __name__ == "__main__":
    s = Solution()
    letters = "abccccdd"
    print(s.longestPalindrome(letters))

