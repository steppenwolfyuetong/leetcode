"""
My idea is to update and record head in each turn.
When the total number becomes 1, head is the only number left.

When will head be updated?
    * if we move from left
    * if we move from right and the total remaining number % 2 == 1

like 2 4 6 8 10, we move from 10, we will take out 10, 6 and 2, head is deleted and move to 4
like 2 4 6 8 10 12, we move from 12, we will take out 12, 8, 4, head is still remaining 2
"""

class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        leftFlag = 1
        step = 1
        head = 1
        remaining = n

        while remaining > 1:
            if leftFlag or remaining % 2 == 1:
                head += step

            remaining = remaining // 2
            step *= 2
            leftFlag = not leftFlag

        return head

if __name__ == "__main__":
    s = Solution()
    print(s.lastRemaining(24))
