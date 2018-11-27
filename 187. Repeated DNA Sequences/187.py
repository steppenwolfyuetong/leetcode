class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        dna = {'A':0,'C':1,'G':2,'T':3}
        table = {}
        rt = set()
        key = 0
        for i in range(len(s)):
            key = ((key << 2) | dna[s[i]]) & 0xfffff
            if i < 9:
                continue
            if key in table:
                rt.add(s[i-9:i+1])
            else:
                table[key] = 1
        return list(rt)

s = Solution()
seq = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
print(s.findRepeatedDnaSequences(seq))
seq = "AAAAAAAAAAA"
print(s.findRepeatedDnaSequences(seq))
