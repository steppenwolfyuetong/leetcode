#include "../leetcode.h"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = accumulate(weights.begin(), weights.end(), 0);    
        int start = *max_element(weights.begin(), weights.end()), end = sum;

        // invariant: start <= target <= end
        while (start < end) {
            int mid = start + ((end - start) >> 1);
            if (count(weights, mid) <= D) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }

    // day count with capacity
    int count(vector<int>& weights, int capacity) {
        int cur = 0, days = 1;                  // at least need one day no matter capacity
        for (const auto& weight : weights) {
            if (cur + weight > capacity) {
                days++;
                cur = 0;
            }
            cur += weight;
        }
        return days;
    }
};

int main() {
    Solution s;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << s.shipWithinDays(weights, 5) << endl;

    weights = {3,2,2,4,1,4};
    cout << s.shipWithinDays(weights, 3) << endl;

    weights = {1,2,3,1,1};
    cout << s.shipWithinDays(weights, 4) << endl;
}
