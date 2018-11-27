import pprint
class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type word: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        result = []
        start = 0
        curLen = 0
        for i in range(len(words)):
            if curLen + len(words[i]) + (i - start) > maxWidth:
                result.append(self.justify(words[start:i],maxWidth))
                start = i
                curLen = len(words[i])
            else:
                curLen += len(words[i])
        lastline = ' '.join(words[start:])
        lastline += (maxWidth - len(lastline)) * ' '
        result.append(lastline)
        return result

    def justify(self, words, maxWidth):
        if len(words) == 1:
            return words[0] + (maxWidth - len(words[0])) * ' '
        count = 0
        for i in range(len(words)):
            count += len(words[i])
        spaces = maxWidth - count
        ave = spaces // (len(words) - 1)
        for i in range(len(words) - 1):
            words[i] += ' ' * ave
        spaces -= ave * (len(words) - 1)
        for i in range(len(words) - 1):
            if spaces:
                words[i] += ' '
                spaces -= 1
            else:
                break
        return ''.join(words)

import pprint
s = Solution()
#words = ["This", "is", "an", "example", "of", "text", "justification."]
#s.fullJustify(words,16)
words = ["Listen","to","many,","speak","to","a","few."]
s.fullJustify(words,6)
