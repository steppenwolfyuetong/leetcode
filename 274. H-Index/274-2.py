class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        count = [0 for i in range(n + 1)]
        for cit in citations:
            if cit > n:
                count[n] += 1
            else:
                count[cit] += 1

        total = 0
        for i in range(n, -1, -1):
            total += count[i]
            if total >= i:
                return i
        return 0
