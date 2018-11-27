from collections import defaultdict
from bisect import bisect_left

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        count = self.createMap(t)
        # lowBound is the minimum index the current char has to be at.
        lowBound = 0
        for char in s:
            if char not in count:
                return False
            charIndexList = count[char]
            # try to find an index that is larger than or equal to lowBound
            index = bisect_left(charIndexList, lowBound)
            if index == len(charIndexList):
                return False
            lowBound = charIndexList[index] + 1
        return True

    def createMap(self, s):
    # create a map. key is char. value is index of apperance in acending order.
        count = defaultdict(list)
        for index, char in enumerate(s):
            count[char].append(index)
        return count


if __name__ == "__main__":
    sol = Solution()
    s = "abc"
    t = "afdlkjbvvmc"
    print(sol.isSubsequence(s,t))
