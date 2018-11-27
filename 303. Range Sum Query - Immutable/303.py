class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.acc = []
        for i in range(len(nums)):
            if i == 0:
                self.acc.append(nums[i])
            else:
                self.acc.append(nums[i] + self.acc[i-1])

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        if i == 0:
            return self.acc[j]
        else:
            return self.acc[j] - self.acc[i-1]

if __name__ == "__main__":
    s = NumArray([-2,0,3,-5,2,-1])
    print(s.sumRange(0,2))
    print(s.sumRange(2,5))
    print(s.sumRange(0,5))

# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.sumRange(1, 2)
