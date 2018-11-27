class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int cur = 0, pre = 0;
        unordered_set<int> modk;
        for(int i = 0; i < nums.size(); i++)
        {
            cur += nums[i];
            int mod = (k == 0) ? cur : cur % k;
            if(modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};
