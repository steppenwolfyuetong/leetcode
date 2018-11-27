#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string rt;        
        if(num < 0)
        {
            rt += '-';
            num = -num;
        }
        else if(num == 0)
        {
            return "0";
        }

        rt += convert(num, 7);
        return rt;
    }

    string convert(int num, int base)
    {
        string rt;
        while(num)
        {
            rt += to_string(num % base);
            num = num / base;
        }
        reverse(rt.begin(), rt.end());
        return rt;
    }
};

int main()
{
    Solution s;
    cout << s.convertToBase7(100) << endl;
    cout << s.convertToBase7(-7) << endl;
    return 0;
}
