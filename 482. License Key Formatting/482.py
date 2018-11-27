class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S = S.upper().replace('-','')
        index = K if len(S) % K == 0 else len(S) % K
        rt = S[:index]
        while index < len(S):
            rt += '-' + S[index : index+K]
            index += K
        return rt;

if __name__ == "__main__":
    s = Solution()
    string = "2-4A0r7-4k"
    k = 4
    print(s.licenseKeyFormatting(string, k))

