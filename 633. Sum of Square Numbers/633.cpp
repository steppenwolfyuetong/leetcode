#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= sqrt(c); a++)
        {
            int b = sqrt(c - a * a);
            if(a * a == c - b * b)
                return true;
        }
        return false;
    }

    bool judgeSquareSum_TwoPointer(int c) {
        int left = 0, right = sqrt(c);
        while(left <= right)
        {
            long long sum = left * left + right * right;
            if(sum == c)
                return true;
            else if(sum < c)
                left++;
            else
                right--;
        }
        return false;
    }
};
