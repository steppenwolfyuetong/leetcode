class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        rt = ["0" for i in range(n)]
        for i in range(14, n, 15):
            rt[i] = "FizzBuzz"
        for i in range(2, n, 3):
            if rt[i] == "0":
                rt[i] = "Fizz"
        for i in range(4, n, 5):
            if rt[i] == "0":
                rt[i] = "Buzz"
        for i in range(n):
            if rt[i] == "0":
                rt[i] = str(i+1)
        return rt
