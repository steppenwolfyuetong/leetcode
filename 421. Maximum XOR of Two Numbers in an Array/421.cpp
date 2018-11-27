#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int rt = 0, mask = 0;
        unordered_set<int> st;
        // search from left to right, find out for each bit is there 
        // two numbers that has different value
        for(int i = 31; i > -1; i--)
        {
            mask = mask | (1 << i);
            st.clear();

            // store prefix of all number with right i bits discarded
            for(auto num : nums)
            {
                st.insert(num & mask);
            }

            // now find out if there are two prefix with different i-th bit
            // if there is, the new rt should be current rt with one 1 bit at i-th position, which is candidate
            // and the two prefix, say A and B, satisfies:
            // A ^ B = candidate
            // so we also have A ^ candidate = B or B ^ candidate = A
            // thus we can use this method to find out if such A and B exists in the set 
            int candidate = rt | (1 << i);
            for(auto prefix : st)
            {
                if(st.find(prefix ^ candidate) != st.end())
                {
                    rt = candidate;
                    break;
                }
            }
        }
        return rt;
    }
};

int main()
{
    int arr[] = {3,10,5,25,2,8};
    vector<int> nums;
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        nums.push_back(arr[i]);
    }

    Solution *s = new Solution();
    cout << s->findMaximumXOR(nums) << endl;
}
