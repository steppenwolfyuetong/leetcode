#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // priority_queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0) {
            return result;
        }

        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            if (p1.first < p2.first) {
                return true;
            } else if (p1.first > p2.first) {
                return false;
            } else {
                return p1.second < p2.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        //priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!pq.empty() && pq.top().second + k <= i) {
                pq.pop();
            }
            pq.push({nums[i], i});
            if (i >= k - 1) {
                result.push_back(pq.top().first);
            }
        }

        return result;
    }

    // multiset
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0) return result;
        multiset<int> w;
        for (int i = 0, n = (int)nums.size(); i < n; i++) {
            if (i >= k)
                w.erase(w.find(nums[i-k]));
            w.insert(nums[i]);
            if (i >= k - 1)
                result.push_back(*w.rbegin());
        }
        return result;
    }


    // Monotonic Queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // store the index of nums, decsend, max size is k
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // remove the index which can't be the maximum in sliding window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{5,4,3,2,1};
    s->maxSlidingWindow(nums, 3);
    nums = {9,10,9,-7,-4,-8,2,-6};
    s->maxSlidingWindow(nums, 5);
    return 0;
}
