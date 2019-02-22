// similar to 845. Longest Mountain in Array
// from left to right to get first transaction, 
// and from right to left to get second transactions,
// get the max(sum(first[i] + second[i]))

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int n = prices.size();
        vector<int> first(n, 0);
        vector<int> second(n, 0);

        int low = prices[0];
        for (int i = 1; i < n; i++) {
            first[i] = max(first[i - 1], prices[i] - low);
            low = min(low, prices[i]);
        }
        
        int high = prices[n - 1];
        for (int i = n - 2; i > -1; i--) {
            second[i] = max(second[i + 1], high - prices[i]);
            high = max(high, prices[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, first[i] + second[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> prices = {5,4,3,2,1};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
