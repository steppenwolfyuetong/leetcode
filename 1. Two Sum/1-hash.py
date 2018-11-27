# You may assume that each input would have exactly one solution.

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self,nums, target):
        map = {}
        for i in range(len(nums)):
            if target - nums[i] in map:
                return map[target - nums[i]] + 1,i + 1
            map[nums[i]] = i
        return -1,-1

print(Solution.twoSum(Solution.twoSum,[1,2,4,7],9))