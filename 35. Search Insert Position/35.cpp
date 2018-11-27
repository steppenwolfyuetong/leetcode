#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator lower = searchLower(nums.begin(), nums.end(), target);
        return lower - nums.begin();
    }

    vector<int>::iterator searchLower(vector<int>::iterator begin, vector<int>::iterator end,int target)
    {
        while(begin < end)
        {
            vector<int>::iterator mid = begin + (end - begin) / 2;
            if(*mid < target)
                begin = mid + 1;
            else
                end = mid;
        }
        return begin;
    }
};

int main()
{
    int arr[] = {1,3,5,6};
    vector<int> vec;
    for(int i = 0; i < 4; i++)
        vec.push_back(arr[i]);
    Solution *s = new Solution;
    cout<<s->searchInsert(vec,2)<<endl;
    return 0;
}
