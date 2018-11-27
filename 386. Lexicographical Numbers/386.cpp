#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rt;
        int cur = 1;
        for(int i = 1; i < n + 1; i++)
        {
            rt.push_back(cur);
            if(cur * 10 <= n)
            {
                cur *= 10;
            }
            else
            {
                if(cur >= n)
                    cur /= 10;
                cur += 1;
                while(cur % 10 == 0)
                {
                    cur /= 10;
                }
            }
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> rt = s->lexicalOrder(27);
    for(int i = 0; i < rt.size(); i++)
    {
        cout << rt[i] << ' ';
    }
    cout << endl;
    return 0;
}

