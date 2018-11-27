"""
 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
"""
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        result = 0
        last = 0
        cur = 0
        for i in range(len(nums)):
            if i > last:
                last = cur
                result += 1
            cur = max(cur, i + nums[i])
        return result

s = Solution()
print(s.jump([2,3,1,1,4]))
