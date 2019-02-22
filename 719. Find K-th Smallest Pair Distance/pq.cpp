#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Pair {
public:
    Pair(int start, int end, int dis): start_(start), end_(end), dis_(dis) {
    }

    int start_, end_, dis_;
};

struct cmp {
    bool operator()(const Pair& a, const Pair &b) {
        return a.dis_ > b.dis_;
    }
};

//TLE
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<Pair, vector<Pair>, cmp> pq;

        // sort the nums, and put pair of (num[i], num[i+1]) into pq, (num[i], num[i+1]) are smallest pair
        // and once remove pair (num[i], num[i+k]) from pq, add (num[i], num[i+k+1]) into pq
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            pq.push(Pair(i, i + 1, nums[i + 1] - nums[i]));
        }

        while (--k) {                       // k is always valid, so no need to check pq.size
            Pair cur = pq.top();
            pq.pop();
            if (cur.end_ < nums.size() - 1) {
                pq.push(Pair(cur.start_, cur.end_ + 1, nums[cur.end_ + 1] - nums[cur.start_]));
            }
        }
        return pq.top().dis_;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,4,5,6,7,8,9,9,10,10};
    int k = 18;
    cout << s.smallestDistancePair(nums, k) << endl;
}
