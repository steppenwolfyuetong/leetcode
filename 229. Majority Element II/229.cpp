#include<map>
#include<vecotr>
using namespace std;

// LeetCode 169
// WizNote
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> table;
        for(int i = 0; i < nums.size(); i++)
        {
            if(table.find(nums[i]) != table.end())
                table[nums[i]]++;
            else
                table[nums[i]] = 1;

            if(table.size() > 3)                   //对应出现频率 修改维护的map的最大size
            {
                for(auto iter = table.begin(); iter != table.end();)
                {
                    iter->second--;
                    if(iter->second == 0)
                        table.erase(iter++);        //注意STL的erase用法 如果直接写为erase(iter),之后再用iter++则找不到下一个迭代器
                                                    //iter = table.erase(iter)这种写法也可以 直接返回了下一个元素的迭代器
                    else
                        iter++;
                }
            }
        }

        // 确认第一遍遍历的结果，看是否确实出现频率高于1/3
        for(auto iter = table.begin(); iter != table.end(); iter++)
            iter->second = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(table.find(nums[i]) != table.end())
                table[nums[i]]++;
        }
        vector<int> rt;
        for(auto iter = table.begin(); iter != table.end(); iter++)
            if(iter->second > nums.size() / 3)
                rt.push_back(iter->first);
        return rt;
    }
};

