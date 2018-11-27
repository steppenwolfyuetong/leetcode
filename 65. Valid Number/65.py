"""
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
"""

import re
class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s):
        ans = re.match("^\s*[+-]?(\d*\.?\d+|\d+\.?\d*)([eE][+-]?\d+)?\s*$",s)
        return bool(ans)

print(Solution.isNumber(Solution.isNumber,"  .     "))
print(Solution.isNumber(Solution.isNumber,"  .1    "))
print(Solution.isNumber(Solution.isNumber,"  -3.   "))
