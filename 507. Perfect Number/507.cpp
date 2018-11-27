#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)
            return false;

        int sum = 1;
        for(int i = 2; i <= sqrt(num); i++)
        {
            if(num % i == 0)
            {
                sum += i;
                sum += num / i;
                if(sum > num)
                    return false;
            }
        }
        return sum == num;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->checkPerfectNumber(28) << endl;
    cout << s->checkPerfectNumber(56) << endl;
    return 0;
}
