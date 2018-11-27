#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        auto p1 = s.begin(), p2 = s.end() - 1;
        string vowels = "aeiouAEIOU";
        while(p1 < p2)
        {
            while(vowels.find(*p1) == string::npos)
                p1++;
            while(vowels.find(*p2) == string::npos)
                p2--;
            if(p1 < p2)
                swap(*p1++, *p2--);
        }
        return s;
    }
};

int main()
{
    string xxx = "leetcode";
    Solution s;
    cout << (s.reverseVowels(xxx)) << endl;
    return 0;
}
