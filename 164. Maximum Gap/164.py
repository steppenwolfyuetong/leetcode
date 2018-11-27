from random import randint

class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        INT_MAX = 2 ** 31 - 1
        INT_MIN = - 2 ** 31
        length = len(nums)
        if length < 2:
            return 0
        mini = min(nums)
        maxi = max(nums)

        gap = (maxi - mini) // (length - 1) + 1             #桶的大小,防止gap为0
        count = (maxi - mini) // gap + 1                    #桶的个数

        mins = [INT_MAX for i in range(count)]          #分别用来统计每个桶内的最小值和最大值
        maxs = [INT_MIN for i in range(count)]

        for num in nums:
            #桶都用左开右闭区间
            index = (num - mini) // gap
            mins[index] = min(mins[index],num)
            maxs[index] = max(maxs[index],num)

        rt = maxs[0] - mins[0]
        curMax = maxs[0]                                #第一个桶肯定不为空
        for i in range(1,count):
            if mins[i] != INT_MAX:
                rt = max(rt,mins[i] - curMax)
                curMax = maxs[i]
        return rt

if __name__ == "__main__":
    s = Solution()
    #nums = [randint(1,100) for i in range(100)]
    #print(s.maximumGap(nums))
    nums = [1,10000000]
    print(s.maximumGap(nums))
