// Hint: Binary search for the answer. How can you check how many pairs have distance <= X?

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // get min distance and max distance, then do the binary search
        sort(nums.begin(), nums.end());

        int low = INT_MAX, high = nums.back() - nums.front();
        for (int i = 1; i < nums.size(); i++) {
            low = min(low, nums[i] - nums[i-1]);
        }

        // invariant: with target is kth smallest distance pair, low <= the distance of target <= high
        //
        // k is the target
        // count of [low, mid] < k, so the target's range must in (mid, high]
        // count of [low, mid] >= k, so the target's range must in [low, mid]
        //
        // and we need to handle the case when low + 1 = high
        // it won't loop forever, so while (left < right)
        while (low < high) {
            int mid = (low + high) / 2;
            if (countPairs(nums, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    // return count of pairs which distance < dis
    int countPairs(vector<int> &nums, int dis) {
        if (cache.find(dis) != cache.end()) {
            return cache[dis];
        }

        int count = 0;
        // count pairs of [begin, *]
        for (auto begin = nums.begin(); begin != nums.end(); begin++) {
            auto end = upper_bound(begin, nums.end(), *(begin) + dis);
            count += end - begin - 1;
        }
        cache[dis] = count;
        return count;
    }

    unordered_map<int, int> cache;
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{1,3,6};
    //cout << s->smallestDistancePair(nums, 3) << endl;
    cout << s->countPairs(nums, 3) << endl;
    return 0;
}
