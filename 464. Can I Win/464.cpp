// 只要知道哪些数字已经被选择（哪些数字没有被选择） 即可知道是否能赢
// 由于maxChoosableInteger <= 20 可以用一个int来表示是否被选择
// 即可用一个map<int, bool>保存子状态 用于缓存

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        if(desiredTotal <= 0)
            return true;

        unordered_map<int, bool> cache;
        vector<bool> used(maxChoosableInteger + 1, false);
        return helper(cache, used, desiredTotal);
    }

    bool helper(unordered_map<int, bool> &cache, vector<bool> &used, int target)
    {
        if(target <= 0)
            return false;
            
        int key = format(used);
        if(cache.find(key) != cache.end())
            return cache[key];
        
        for(int i = 1; i < used.size(); i++)
        {
            if(!used[i])
            {
                used[i] = true;
                // 另一个选手失败，即本人获胜
                if(!helper(cache, used, target - i))
                {
                    cache[key] = true;
                    used[i] = false;
                    return true;
                }
                used[i] = false;
            }
        }
        cache[key] = false;
        return false;
    }

    int format(vector<bool> &used)
    {
        int num = 0;
        for(auto boolean : used)
        {
            if(boolean)
            {
                num |= 1;
            }
            num <<= 1;
        }
        return num;
    }
};

int main()
{
    Solution *s = new Solution();
    int maxChoosableInteger = 18;
    int desiredTotal = 79;
    cout << s->canIWin(maxChoosableInteger, desiredTotal);
    return 0;
}
