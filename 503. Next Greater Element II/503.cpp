#include <stack>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> table;

        vector<int> rt(nums.size(), -1);
        //与496不同的是，栈里面保存的是索引，不然如果有相同元素区分不出来
        //遍历两次
        for(int k = 0; k < 2; k++)
        {
            for(int index = 0; index < nums.size(); index++)
            {
                //遇到比栈顶元素大的元素 更新nextGreaterElement
                while(!stk.empty() && nums[index] > nums[stk.top()])
                {
                    rt[stk.top()] = nums[index];
                    stk.pop();
                }
                //只有第一次遍历入栈
                if(k == 0)
                {
                    stk.push(index);
                }
            }
        }

        return rt;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1,2,1};

    vector<int> rt = s.nextGreaterElements(nums);
    for(auto num : rt)
        cout << num << ' ';
    cout << endl;
    return 0;
}
