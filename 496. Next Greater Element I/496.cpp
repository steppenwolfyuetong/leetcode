#include <stack>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        /*
         * We use a stack to keep a decreasing sub-sequence,
         * whenever we see a number x greater than stack.peek() we pop all elements less than x and for all the popped ones,
         * their next greater element is x
         */
        stack<int> stk;
        unordered_map<int, int> table;
        for(auto num : nums)
        {
            while(!stk.empty() && num > stk.top())
            {
                table[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        while(!stk.empty())
        {
            table[stk.top()] = -1;
            stk.pop();
        }
        
        vector<int> rt;
        for(int i = 0; i < findNums.size(); i++)
        {
            rt.push_back(table[findNums[i]]);
        }
        return rt;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};

    vector<int> rt = s.nextGreaterElement(nums1, nums2);
    for(auto num : rt)
        cout << num << ' ';
    cout << endl;
    return 0;
}
