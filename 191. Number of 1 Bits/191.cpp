#include<iostream>
using namespace std;
typedef unsigned int uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rt = 0;
        while(n)
        {
            if(n & 1)
                rt += 1;
            n >>= 1;
        }
        return rt;
    }

    int hammingWeight1(uint32_t n)
    {
        //Each time of "n &= n - 1", we delete one '1' from n.
        int res = 0;
        while(n)
        {
            n &= n - 1;
            res++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(97) << endl;
	cout << s.hammingWeight1(97) << endl;
}
