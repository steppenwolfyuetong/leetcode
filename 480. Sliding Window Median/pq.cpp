#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
    // TLE, algorithm is ok
    // same as 295, but since we need to remove num, a lot of useless pop/push
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> median;
        
        // invariant: after we add and remove, always makes size(small) == size(big) || size(small) == size(big) + 1
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
            // we need to remove nums[i - k]
            if (i >= k) {
                remove(nums[i - k]);
            }
            rebalance();

            // output median
            if (i >= k - 1) {
                median.emplace_back(small.size() > big.size() ? small.top() : ((double)small.top() + (double)big.top()) / 2.0);
            }
        }

        return median;
    }

    void insert(int num) {
        if (small.empty() || num < small.top()) {
            small.push(num);
        } else {
            big.push(num);
        }
    }

    void remove(int num) {
        if (num <= small.top()) {
            while (small.top() != num) {
                big.push(small.top());
                small.pop();
            }
            small.pop();
        } else {
            while (big.top() != num) {
                small.push(big.top());
                big.pop();
            }
            big.pop();
        }
    }

    void rebalance() {
        while (small.size() < big.size()) {
            small.push(big.top());
            big.pop();
        }

        while (small.size() > big.size() + 1) {
            big.push(small.top());
            small.pop();
        }
    }

private:
    priority_queue<int> small;                              // the small half of sliding window
    priority_queue<int, vector<int>, greater<int>> big;     // the big half of sliding window
};

int main()
{
    Solution *s = new Solution();
    int arr[] = {1,3,-1,-3,5,3,6,7};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<double> rt = s->medianSlidingWindow(nums, 3);
    for(auto median : rt)
        cout << median << endl;
    return 0;
}
