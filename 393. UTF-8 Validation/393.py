"""
   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
"""

class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        index = 0
        while index < len(data):
            count = self.judgeByte(data[index])
            if count < 0:
                return False
            else:
                for i in range(1, count):
                    if index + i >= len(data):
                        return False
                    if data[index + i] & 0b11000000 != 0b10000000:
                        return False
                index += count
        return True

    def judgeByte(self, val):
        if val & 0b11111000 == 0b11110000:
            return 4
        elif val & 0b11110000 == 0b11100000:
            return 3
        elif val & 0b11100000 == 0b11000000:
            return 2
        elif val & 0b10000000 == 0:
            return 1
        else:
            return -1

if __name__ == "__main__":
    s = Solution()
    data = [197, 130, 1]
    print(s.validUtf8(data))
    data = [235, 140, 4]
    print(s.validUtf8(data))
