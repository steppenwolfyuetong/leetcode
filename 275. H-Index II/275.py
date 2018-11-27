class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations:
            return 0

        left = 0
        right = len(citations) - 1
        while left <= right:
            mid = (left + right) // 2
            if citations[mid] == len(citations) - mid:
                return citations[mid]
            elif citations[mid] < len(citations) - mid:
                left = mid + 1
            else:
                right = mid - 1
        return len(citations) - left

s = Solution()
cit = [0,1,3,5,6]
print(s.hIndex(cit))

