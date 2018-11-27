#include <iostream>
using namespace std;
typedef int uint32_t;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
    
    uint32_t reverseBits1(uint32_t n) {
        uint32_t rt = 0;
        for(int i = 0; i < 32; i++)
        {
            rt <<= 1;
            rt |= n & 1;
            n >>= 1;
        }
        return rt;
    }
};

int main()
{
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    cout << s.reverseBits1(43261596) << endl;
    return 0;
}
