#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1)
            return s;
        int len = s.length();
        string *str = new string[nRows];
        int row = 0, step = 1;
        for(int i = 0; i < len; i++)
        {
            str[row].push_back(s[i]);
            if(row ==0)
                step = 1;
            else if (row == nRows - 1)
                step = -1;
            row += step;
        }
        s.clear();
        for(int j = 0; j < nRows; j++)
            s.append(str[j]);
        delete[] str;
        return s;
    }
};

int main()
{
    Solution *s = new Solution;
    cout << s->convert("PAYPALISHIRING",3) << endl;
}
