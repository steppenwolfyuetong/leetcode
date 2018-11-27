#include <cmath>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

/*
 * the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */


class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0 || t < 0 || nums.size() < 2)
            return false;
        // set自动排序
        set<int> rec;               // 维持一个长度为k + 1的桶，|i-j| <= k
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k)               // 删除头
                rec.erase(nums[i-k-1]);
            set<int>::iterator pos = rec.lower_bound(nums[i] - t);      //找到第一个大于等于nums[i] - t的数
            if(pos != rec.end() && abs(nums[i] - *pos) <= t)            //检查条件
                return true;
            rec.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(6);
    cout << s->containsNearbyAlmostDuplicate(nums, 2, 0) << endl;
    return 0;
}
