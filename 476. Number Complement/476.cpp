#include <iostream>
using namespace std;

/*
num          = 00000101
mask         = 11111000
~mask & ~num = 00000010
*/
 

class Solution {
public:
    int findComplement(int num) {
        // 由于存在溢出 只能在python中用
        /*
        int i = 1;
        while(i <= num)
        {
            i <<= 1;
        }
        return (i - 1) ^ num;
        */
        
        unsigned int mask = ~0;
        while(num & mask)
        {
            mask <<= 1;
        }
        return ~mask & ~num;
    }
};

int main()
{
    Solution *s = new Solution();
    int num = 5;
    cout << s->findComplement(num) << endl;
    return 0;
}
