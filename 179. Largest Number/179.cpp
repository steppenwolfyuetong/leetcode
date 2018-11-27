#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(const string s1, const string s2)
{
    return (s1 + s2) > (s2 + s1);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        stringstream stream;
        vector<string> str(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            stream << nums[i];
            stream >> str[i];
            stream.clear();
        }
        sort(str.begin(), str.end(), cmp);
        string rt = "";
        for(int i = 0; i < str.size(); i++)
        {
            rt += str[i];
        }
		//ȥ????ͷ??0
		int index = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] != "0")
			{
				index = i;
				break;
			}
		}
        if(index == 0 && str[index] == "0")
            return "0";
        else
            return rt.substr(index);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(30);
    nums.push_back(34);
    nums.push_back(5);
    nums.push_back(9);
    cout << s.largestNumber(nums) << endl;;
}
