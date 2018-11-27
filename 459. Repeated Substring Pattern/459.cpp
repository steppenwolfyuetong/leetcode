class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.length();
        for(int i = len / 2; i > 0; i--)
        {
            if(len % i == 0)
            {
                int count = len / i;
                string sub = str.substr(0, i);
                string repeated = "";
                for(int j = 0; j < count; j++)
                {
                    repeated += sub;
                }
                if(repeated == str)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
