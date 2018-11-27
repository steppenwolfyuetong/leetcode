/*
The idea is pretty simple. If we look at the order we can find out we just keep adding digit from 0 to 9 to every digit and make it a tree.
Then we visit every node in pre-order. 
       1        2        3    ...
      / \      / \      / \
   10 ...19  20...29  30...39   ....
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rt;
        for(int i = 1; i < 10; i++)
        {
            dfs(rt, i, n);
        }
        return rt;
    }
private:
    void dfs(vector<int> &nums, int cur, int n)
    {
        if(cur > n)
            return;

        nums.push_back(cur);
        for(int i = 0; i < 10; i++)
        {
            if(10 * cur + i > n)
                return;
            dfs(nums, 10 * cur + i, n);
        }
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
    return 0;
}

