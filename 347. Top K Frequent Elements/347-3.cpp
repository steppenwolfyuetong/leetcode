//bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> rt;
        if(nums.empty())
            return rt;

        unordered_map<int, int> cnt;
        for(auto num : nums)
        {
            cnt[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for(auto kv : cnt)
        {
            bucket[kv.second].push_back(kv.first);
        }

        for(int i = bucket.size() - 1; i > -1; i--)
        {
            for(int j = 0; j < bucket[i].size(); j++)
            {
                rt.push_back(bucket[i][j]);
                if(rt.size() == k)
                    return rt;
            }
        }
        return rt;
        
    }
};
