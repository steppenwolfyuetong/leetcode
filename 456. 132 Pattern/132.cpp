#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // pair<int, int>保存当前的<min, max>
        stack<pair<int, int>> stk;
        for(auto& num : nums)
        {
            if(stk.empty() || num < stk.top().first)
            {
                stk.push(make_pair(num, num));
            }
            else if(num > stk.top().first)
            {
                // 满足132 Pattern
                if(num < stk.top().second)
                {
                    return true;
                }
                pair<int, int> last = stk.top();
                stk.pop();
                last.second = num;
                while(!stk.empty() && num > stk.top().second)
                {
                    stk.pop();
                }
                if(!stk.empty() && stk.top().first < num)
                {
                    return true;
                }
                stk.push(last);
            }
        }
        return false;
    }

};

int main()
{
    int arr[] = {3,5,0,3,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    Solution *s = new Solution();
    cout << s->find132pattern(nums) << endl;
}
