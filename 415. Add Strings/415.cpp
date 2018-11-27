#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        string rt;
        int carry = 0;
        while(index1 > -1 || index2 > -1 || carry)
        {
            int sum = carry;
            if(index1 > -1)
            {
                sum += num1[index1] - '0';
                index1--;
            }
            if(index2 > -1)
            {
                sum += num2[index2] - '0';
                index2--;
            }
            rt.push_back('0' + sum % 10);
            carry = sum / 10;
        }
        reverse(rt.begin(), rt.end());
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    string num1 = "123456789";
    string num2 = "987654321";
    cout << s->addStrings(num1, num2) << endl;
    return 0;
}
