#include "../leetcode.h"

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3) {
            return false;
        }
        int target = sum / 3;
        int cur = 0, count = 0;
        for (const auto& num : A) {
            cur += num;
            if (cur == target) {
                cur = 0;
                count++;
            }        
        }
        return count == 3;
    }
};

int main() {
    Solution s;
    vector<int> A = {3,3,6,5,-2,2,5,1,-9,4};
    cout << s.canThreePartsEqualSum(A) << endl;
}
