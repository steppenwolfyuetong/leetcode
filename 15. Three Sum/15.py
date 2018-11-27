#!python
class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def threeSum(self, nums):
        result=[]
        if len(nums) < 3:
            return result
        nums = sorted(nums)
        for i in range(len(nums)-2):
            if i != 0 and nums[i] == nums[i-1]:
                continue
            j = i + 1
            k = len(nums) - 1
            while(j < k):
                if nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                elif nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                else:
                    result.append((nums[i],nums[j],nums[k]))
                    j += 1
                    k -= 1
                    while nums[j] == nums[j-1] and j < k:
                        j += 1
                    while nums[k] == nums[k+1] and j < k:
                        k -= 1
        return result

print(Solution.threeSum(Solution.threeSum,[-1,0,1,2,-1,-1,-4]))
