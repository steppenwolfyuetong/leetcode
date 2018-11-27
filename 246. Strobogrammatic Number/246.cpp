/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    Write a function to determine if a number is strobogrammatic. The number is represented as a string.
    For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num)
    {
        map<char, char> map;
        map['0'] = '0';
        map['1'] = '1';
        map['6'] = '9';
        map['8'] = '8';
        map['9'] = '6';
        
        int left = 0, right = num.size() - 1;
        while(left <= right)
        {
            if (map.find(num[left]) == map.end() ||
                map[num[left]] != num[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->isStrobogrammatic("69") << endl;
    return 0;
}
