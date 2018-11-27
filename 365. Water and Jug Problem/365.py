"""
The basic idea is to use the property of Bézout's identity and check if z is a multiple of GCD(x, y)
Quote from wiki:
Bézout's identity (also called Bézout's lemma) is a theorem in the elementary theory of numbers:
let a and b be nonzero integers and let d be their greatest common divisor. Then there exist integers x and y such that ax+by=d
In addition, the greatest common divisor d is the smallest positive integer that can be written as ax + by
every integer of the form ax + by is a multiple of the greatest common divisor d.

If a or b is negative this means we are emptying a jug of x or y gallons respectively.
Similarly if a or b is positive this means we are filling a jug of x or y gallons respectively.
x = 4, y = 6, z = 8.
GCD(4, 6) = 2
8 is multiple of 2
so this input is valid and we have:
-1 * 4 + 6 * 2 = 8
In this case, there is a solution obtained by filling the 6 gallon jug twice and emptying the 4 gallon jug once. (Solution. Fill the 6 gallon jug and empty 4 gallons to the 4 gallon jug. Empty the 4 gallon jug. Now empty the remaining two gallons from the 6 gallon jug to the 4 gallon jug. Next refill the 6 gallon jug. This gives 8 gallons in the end)
"""

class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if x + y < z:
            return False
        if x == z or y == z or x + y == z:
            return True

        return z % self.GCD(x, y) == 0

    # from fractions import gcd

    def GCD(self, a, b):
        while b != 0:
            temp = b
            b = a % b
            a = temp
        return a

if __name__ == "__main__":
    s = Solution()
    print(s.canMeasureWater(3,5,4))


