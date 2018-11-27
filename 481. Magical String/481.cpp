#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int index = 2;
        while(s.size() < n)
        {
            // 异或3即可以1->2或2->1
            string tail(s[index] - '0', s.back() ^ 3);
            index++;
            s += tail;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};

int main()
{
    Solution *s = new Solution();
    int n = 555;
    cout << s->magicalString(n) << endl;
    return 0;
}
