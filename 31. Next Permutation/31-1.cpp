#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void display(vector<int> &nums)
{
    for(int num : nums)
        cout << num << ' ';
    cout << endl;
}

class Solution {
public:
    // nextPermutation也就是找到下一个比当前数大的数
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        
        // {1,9,8,4,7,6,5,3,1}
        // 从低位开始 找到第一个降序的元素 即4
        // 找到降序的元素 也就能找到下一个比当前数大的数
        vector<int>::iterator firstDesc = nums.end() - 2;
        for(; firstDesc >= nums.begin(); firstDesc--)
            if(*(firstDesc) < *(firstDesc + 1))
                break;
        
        // 从低位开始 找到第一个比firstDesc大的数bigger 即5
        // 并与firstDesc交换 交换这个操作不会影响firstDesc右侧的升降关系
        if(firstDesc >= nums.begin())
        {
            vector<int>::iterator bigger = nums.end() - 1;
            for(; bigger > firstDesc; bigger--)
                if(*(firstDesc) < *(bigger))
                    break;
            swap(*firstDesc, *bigger);
        }
        
        // 交换后 firstDesc并不是最小值 由于firstDesc右侧都是从大到小 再逆序一下即可 变为从小到大 变为最小值
        reverse(firstDesc + 1, nums.end());
    }
};


int main()
{
    Solution *s = new Solution();
    vector<int> nums{1,9,8,4,7,6,5,3,1};
    display(nums);
    s->nextPermutation(nums);
    display(nums);
    return 0;
}
