class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        if len(secret) != len(guess):
            return ""

        sTable = [0 for i in range(10)]
        gTable = [0 for i in range(10)]
        aCount, bCount = 0, 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                aCount += 1
            else:
                sTable[int(secret[i])] += 1
                gTable[int(guess[i])] += 1
        for i in range(10):
            bCount += min(sTable[i],gTable[i])
        return str(aCount) + "A" + str(bCount) + "B"

if __name__ == "__main__":
    s = Solution()
    s.getHint("1234","2342")
