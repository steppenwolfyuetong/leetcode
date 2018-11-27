"""
Problem Description:

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
"""

# 还有种更变态的
# https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms

class Solution(object):
    def canWin(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        for i in range(len(s) - 1):
            if s[i:i+2] == "++":
                if not self.canWin(s[:i] + "--" + s[i+2:]):
                    return True
        return False

if __name__ == "__main__":
    s = Solution()
    print(s.canWin("++++"))

