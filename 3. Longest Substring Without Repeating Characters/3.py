class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        char = {}
        start = 0
        result = 0
        for i in range(len(s)):
            if s[i] not in char:
                char[s[i]] = i
                continue
            else:
                if char[s[i]] >= start:
                    result = max(result, i - start)
                    start = char[s[i]] + 1
                char[s[i]] = i
        return max(len(s) - start, result)

s = Solution()
print(s.lengthOfLongestSubstring("rjxlmqdhxzfdjwpaubjqkveulfseabxrmwfyniiminprlhtgicyuyeqlljslmpfyokwduepetexfnsnwvnsvtjiesaresyegkajh"))
