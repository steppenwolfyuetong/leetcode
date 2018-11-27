#include <iostream>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 2147483647)
            return 32;

        int rt = 0;
        while(n != 1)
        {
            if((n & 1) == 0)
            {
                n = n >> 1;
            }
            else
            {
                if(n != 3 && (n + 1) % 4 == 0)
                    n += 1;
                else
                    n -= 1;
            }
            rt += 1;
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->integerReplacement(3) << endl;
    cout << s->integerReplacement(7) << endl;
    cout << s->integerReplacement(31) << endl;
    cout << s->integerReplacement(33) << endl;
    cout << s->integerReplacement(27) << endl;
    return 0;
}
