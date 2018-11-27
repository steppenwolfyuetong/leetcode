/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    Find all strobogrammatic numbers that are of length = n.
    For example, Given n = 2, return ["11","69","88","96"].
 */

/*
 * 0 -- 0 不能在开头结尾处使用 除非n = 1
 * 1 -- 1 8 -- 8 没有限制
 * 6 -- 9 9 -- 6 当n为奇数时不能在最中间那个数使用 例如161和191并不满足题意
 */

#include <map>
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
	
    vector<string> findStrobogrammatic(int n)
    {
        vector<string> result;
        string cur;
        dfs(n, cur, result);
        return result;
    }

    void dfs(int len, string cur, vector<string> &result)
    {
        if(cur.size() == len)
        {
            result.push_back(cur);
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
            dfs(len, cur, result);
            cur = save;
        }
    }
private:
	vector<pair<char, char>> table;
};

int main()
{
    Solution *s = new Solution();
    vector<string> result = s->findStrobogrammatic(3);
    for(int i = 0; i < result.size(); i++)
    	cout << i << ' ' << result[i] << endl;
    return 0;
}
