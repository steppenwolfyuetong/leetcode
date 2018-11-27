#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;

        unordered_set<int> rec(nums.begin(), nums.end());
        int result = 1;
        for(auto num : nums)
        {
            if(rec.find(num) == rec.end())
                continue;

            rec.erase(num);
            int prev = num - 1, next = num + 1;
            while(rec.find(prev) != rec.end())
                rec.erase(prev--);
            while(rec.find(next) != rec.end())
                rec.erase(next++);
            result = max(result, next - prev - 1);
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums{100,4,200,1,3,2};
    cout << s->longestConsecutive(nums) << endl;
    return 0;
}
