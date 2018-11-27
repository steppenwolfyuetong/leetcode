class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = list(map(int,version1.split('.')))
        v2 = list(map(int,version2.split('.')))
        for i,j in zip(v1,v2):
            if i == j:
                continue
            else:
                return 1 if i > j else -1
        #Trailing 0...
        if len(v1) < len(v2):
            for suffix in v2[len(v1):len(v2)]:
                if suffix != 0:
                    return -1
        elif len(v1) > len(v2):
            for suffix in v1[len(v2):len(v1)]:
                if suffix != 0:
                    return 1
        return 0

s = Solution()
print(s.compareVersion("1.2.3.5.0.0.0","1.2.3.5"))
