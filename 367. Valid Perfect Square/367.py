class Solution(object):
    # binary search
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        low = 1
        high = num
        while low <= high:
            mid = low + (high - low) // 2
            if mid * mid < num:
                low = mid + 1
            elif mid * mid > num:
                high = mid - 1
            else:
                return True
        return False

    # 1 + 3 + 5 + 7 + 9...
    def isPerfectSquare1(self, num):
        """
        :type num: int
        :rtype: bool
        """
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0

    # Newton
    def isPerfectSquare2(self, num):
        """
        :type num: int
        :rtype: bool
        """
        x = num
        while x * x > num:
            x = (x + num // x) // 2
        return x * x == num
