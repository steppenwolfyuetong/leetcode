class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int slow = i, fast = getIndex(i, nums);
        }
    }

    int getIndex(int i, vector<int>& nums)
    {
        if(i + nums[i] >= 0)
            return (i + nums[i]) % n;
        else
            n + ((i + nums[i]) % n);
    }
};
