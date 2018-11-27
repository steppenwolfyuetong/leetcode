class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> rt;

        for(auto num : nums1)
            dict[num]++;

        for(auto num : nums2)
        {
            if(dict.find(num) != dict.end() && dict[num]-- > 0)
            {
                rt.push_back(num);
            }
        }
        return rt;
    }
};
