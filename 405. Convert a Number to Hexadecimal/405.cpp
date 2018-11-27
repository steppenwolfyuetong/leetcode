#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(!num)
            return "0";

        string rt = "";
        int count = 0;
        char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(num && count < 8)
        {
            // 对16求余
        	rt = hex[num & 15] + rt;
            // 除以16
            num >>= 4;
            count++;
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    int num = 26;
    cout << s->toHex(num) << endl;
    num = -1;
    cout << s->toHex(num) << endl;
    return 0;
}
