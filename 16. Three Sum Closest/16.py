# You may assume that each input would have exactly one solution.
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def threeSumClosest(self, nums, target):
        if len(nums) < 3:
            return None
        result = None
        nums = sorted(nums)
        print(nums,"\n")
        diff = max(abs(3*nums[0]-target),abs(3*nums[-1]-target)) + 1
        for i in range(0,len(nums)-2):
            j = i + 1
            k = len(nums) - 1
            print(i,j,k)
            print(nums[i],nums[j],nums[k],"\n")
            while(j < k):
                if nums[i] + nums[j] + nums[k] == target:
                    return target
                if abs(target - (nums[i] + nums[j] + nums[k])) < diff:
                    diff = abs(target - (nums[i] + nums[j] + nums[k]))
                    result = nums[i] + nums[j] + nums[k]            
                # 由于是寻找closest 不能同时j++,k--
                if nums[i] + nums[j] + nums[k] < target:
                    j += 1
                    while nums[j] == nums[j-1]:
                        j += 1
                else:
                    k -= 1
                    while nums[k] == nums[k+1]:
                        k -= 1
        return result
        
print(Solution.threeSumClosest(Solution.threeSumClosest,[0,2,1,-3],1))
