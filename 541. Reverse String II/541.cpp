#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
    	int len = s.size();
        int index = 0;
        string rt = "";
        
        while(index < s.size())
        {
            string sub = s.substr(index, k);
            reverse(sub.begin(), sub.end());
            rt += sub;
    
            if(index + k < s.size())
            {
                sub = s.substr(index + k, k);
                rt += sub;
            }
            index += 2 * k;
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->reverseStr("abcdefg", 2) << endl;
    cout << s->reverseStr("", 2) << endl;
    return 0;
}
