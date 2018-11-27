/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
    For example,
    Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
    Note:
    Because the range might be a large number, the low and high numbers are represented as string.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	Solution()
	{
		table.push_back(make_pair('0','0'));
		table.push_back(make_pair('1','1'));
		table.push_back(make_pair('6','9'));
		table.push_back(make_pair('8','8'));
		table.push_back(make_pair('9','6'));
	}

    int strobogrammaticInRange(string low, string high)
    {
        int result = 0;
        for(int i = low.size(); i <= high.size(); i++)
        {
            string cur = "";
            dfs(i, cur, result, low, high);
        }
        return result;
    }

    void dfs(int len, string cur, int &result, string low, string high)
    {
        if(cur.size() == len)
        {
            if(stoi(low) <= stoi(cur) && stoi(cur) <= stoi(high))
            {
                cout << cur << endl;
                result++;
            }
            return;
        }

        for(auto num : table)
        {
            string save = cur;
            if(cur.size() == 0 && len % 2 == 1)
            {
                if(num.first == '6' || num.first == '9')        // 6,9不能在奇数长度最中间那个
                    continue;
                cur = num.first;
            }
            else if(cur.size() == len - 2)
            {
                if(num.first == '0')
                    continue;
                cur = num.first + cur + num.second;
            }
            else
            {
                cur = num.first + cur + num.second;
            }
            dfs(len, cur, result, low, high);
            cur = save;
        }
    }
private:
	vector<pair<char, char>> table;
};

int main()
{
    Solution *s = new Solution();
    //cout << s->strobogrammaticInRange("50", "100") << endl;
    //cout << s->strobogrammaticInRange("50", "102") << endl;
    cout << s->strobogrammaticInRange("50", "1000") << endl;
    return 0;
}
