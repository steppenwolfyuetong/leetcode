#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int rt = -1;
        for(int i = 0; i < strs.size(); i++)
        {
        	int len = strs[i].size();
        	if(len < rt)
        		continue;
        		
            bool flag = true;
            for(int j = 0; j < strs.size(); j++)
            {
                if(i != j && isCommon(strs[i], strs[j]))
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                rt = len;
            }
        }
        return rt;
    }

    bool isCommon(string a, string b)
    {
        int countA = a.size(), countB = b.size();
        while(countA > 0 && countB > 0)
        {
            int i = a.size() - countA;
            int j = b.size() - countB;
            if(a[i] == b[j])
            {
                countA--;
                countB--;
            }
            else
            {
                countB--;
            }
        }
        return countA == 0;
    }
};

int main()
{
	Solution *s = new Solution();
    vector<string> strs({"aba", "cdc", "eae"});
    cout << s->findLUSlength(strs);
    return 0;
}
