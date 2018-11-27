# 用cache存储两个数的和 O(n^3)

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[][]}
    def fourSum(self, nums, target):
        result=[]
        nums = sorted(nums)
        print(nums)
        x = len(nums)
        cache = {}
        for i in range(x-1):
            for j in range(i+1,x):
                if nums[i] + nums[j] in cache:
                    cache[nums[i]+nums[j]].append([i,j])
                else:
                    cache[nums[i]+nums[j]]=[[i,j]]
        
        for m in range(x-1):
            for n in range(m+1,x):
                key = target - nums[m] - nums[n]
                if key in cache:
                    for i in range(len(cache[key])):
                        if m <= cache[key][i][1]:
                            continue
                        else:
                            ans = [nums[cache[key][i][0]],nums[cache[key][i][1]],nums[m],nums[n]]
                            if ans not in result:
                                result.append(ans)
                        print(cache[key][i][0],cache[key][i][1],m,n)
        return result
        
print(Solution.fourSum(Solution.fourSum,[-3,-2,-1,0,0,1,2,3], 0))
