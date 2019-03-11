#include "../leetcode.h"

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        sort(rods.begin(), rods.end(), greater<int>());        
        int sum = accumulate(rods.begin(), rods.end(), 0);
        int result = 0;
        dfs(rods, 0, 0, sum, 0, result);
        return result;
    }

    // left/right is billboard height of each side
    // index points to next rod
    void dfs(vector<int>& rods, int left, int right, int remain, int index, int& result) {
        if (abs(left - right) > remain || 
            left + right + remain <= result * 2) {
            return;
        }

        if (left == right && result < left) {
            result = left;
        }

        if (index == rods.size()) {
            return;
        }
         
        remain -= rods[index];
        dfs(rods, left + rods[index], right, remain, index + 1, result);
        dfs(rods, left, right + rods[index], remain, index + 1, result);
        dfs(rods, left, right, remain, index + 1, result);
    }
};

int main() {
    Solution s;
    vector<int> rods;
    rods = {1,2,3,4,5,6};
    cout << s.tallestBillboard(rods) << endl;
    rods = {1,2,3,6};
    cout << s.tallestBillboard(rods) << endl;
    rods = {1,2};
    cout << s.tallestBillboard(rods) << endl;
}
