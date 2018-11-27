"""
比较取巧的方法
(num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);

(num - 1) % 3 == 0
可以根据归纳总结法证明：
假设(4^n - 1) % 3 = 0
  4^(n+1) - 1 = 4 * 4^n - 1
= 3 * 4^n + (4^n - 1)
显然两部分均能够被3整除 则4^(n+1) - 1可以被3整除
"""
class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num > 0 and (num & (num - 1)) == 0 and (num - 1) % 3 == 0
