import collections
from heapq import heappush, heappop, heapify

"""
核心思想：两个堆 一个最小堆(保存较大的数) 一个最大堆(保存较小的数) 由此找中位数
由于移动窗的时候 需要在堆中去掉某个数 因此还需要一个map保存对应数的索引
PS: heapq建立的为最小堆 键值最小的优先出队列

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
"""

"""
        '''Similar to the median stream problem, we maintain 2 heaps which represent
        the top and bottom halves of the window.
        Since deletion from a heap is an O(1) operation, we perform it lazily.

        At any time, if a number leaves a window, we delete it if it is at the top
        of the heap. Else, we stage it for deletion, but alter the count of this
        half of the array.

        When this element eventually comes to the top of the heap at a later instance,
        we perform the staged deletions.
        '''
"""

class Solution(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        rt = []
        topHeap, bottomHeap = nums[:k], []                  # topHeap为最小堆 bottomHeap为最大堆
        heapify(topHeap)
        countNumToDelete = collections.defaultdict(int)

        while len(topHeap) - len(bottomHeap) > 1:
            heappush(bottomHeap, -heappop(topHeap))         # 取反

        for i in range(k, len(nums) + 1):
            # 取中位数
            if k % 2:
                rt.append(topHeap[0])
            else:
                rt.append((topHeap[0] - bottomHeap[0]) / 2.0)

            if i == len(nums):
                break

            numToAdd, numToDelete = nums[i], nums[i - k]
            balance = 0

            # numToDelete在topHeap中
            if numToDelete >= topHeap[0]:
                balance -= 1
                if numToDelete == topHeap[0]:
                    heappop(topHeap)
                else:
                    countNumToDelete[numToDelete] += 1
            else:
                balance += 1
                if numToDelete == -bottomHeap[0]:
                    heappop(bottomHeap)
                else:
                    countNumToDelete[numToDelete] += 1

            if topHeap and numToAdd >= topHeap[0]:
                balance += 1
                heappush(topHeap, numToAdd)
            else:
                balance -= 1
                heappush(bottomHeap, -numToAdd)

            # balance = -2/0/2
            if balance > 0:
                heappush(bottomHeap, -heappop(topHeap))
            elif balance < 0:
                heappush(topHeap, -heappop(bottomHeap))

            # 当要删除的数到堆顶的时候再进行删除 不在堆顶的时候不用操作
            while topHeap and countNumToDelete[topHeap[0]]:
                countNumToDelete[topHeap[0]] -= 1
                heappop(topHeap)
            while bottomHeap and countNumToDelete[-bottomHeap[0]]:
                countNumToDelete[-bottomHeap[0]] -= 1
                heappop(bottomHeap)

        return list(map(float, rt))

if __name__ == "__main__":
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    s = Solution()
    print(s.medianSlidingWindow(nums, k))
