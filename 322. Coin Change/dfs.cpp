#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Time complexity: O(amount^n/(coin_0*coin_1*…*coin_n))
    // Space complexity: O(n)
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int result = INT_MAX;
        dfs(coins, amount, 0, 0, result);
        return result == INT_MAX ? -1 : result;
    }

    // amount is remaining to make up
    // index is the index of next coin try to use
    void dfs(vector<int> &coins, int amount, int count, int index, int &result) {
        if (amount == 0) {
            result = min(count, result);
            return;
        }
        if (index == coins.size()) {
            return;
        }

        int k = amount / coins[index];
        // count + i < result to avoid useless dfs
        for (int i = k; i >= 0 && count + i < result; i--) {
            dfs(coins, amount - i * coins[index], count + i, index + 1, result);
        }

    }
};

int main() {
    Solution *s = new Solution();
    vector<int> coins {1,2,5};
    cout << s->coinChange(coins, 11) << endl;

    coins = {288,160,10,249,40,77,314,429};
    cout << s->coinChange(coins, 9208) << endl;

    return 0;
}
