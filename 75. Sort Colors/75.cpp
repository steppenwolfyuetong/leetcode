#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	/*
    // 两次扫描
    // we can use fill_n
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        for(int i = 0, index = 0; i < 3; i ++)
            for(int j = 0; j < count[i]; j++)
                nums[index++] = i;
	*/
    
    // 两个指针 向中间扫描
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for(int i = 0; i < blue + 1;)
        {
            if(nums[i] == 0)
                swap(nums[i++],nums[red++]);
            else if(nums[i] == 2)
                swap(nums[i],nums[blue--]);
            else
                i++;
        }
    }
};

int main()
{
    Solution *s = new Solution;
    int a[10] = {0,2,1,2,0,1,0,2,1,2};
    vector<int> vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(a[i]);
    s->sortColors(vec);
    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<' ';
    cout<<endl;
    return 0;
}
