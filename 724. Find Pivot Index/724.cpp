/*
If I understand the problem correctly, pivot index is included in both sub-arrays (left and right):
[-1,-1,-1,0,1,1] broken up into two sub-arrays at index 0 would mean:
left sub-array: [-1], sum = -1
right sub-array: [-1,-1,-1,0,1,1], sum = -1
*/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int num : nums) 
            total += num;

        int sum = 0;
        for (int i = 0; i < nums.size(); sum += nums[i++]) {
            if (sum * 2 == total - nums[i])
                return i;
        }
        
        return -1;
    }
};
