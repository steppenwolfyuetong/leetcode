// 1. need to eat at least piles.size() hours.
// 2. select piles[i] with speed K, time is ceil(piles[i] / K)
// 3. binary search to find K, low <= K <= high
//

#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        // handle low + 1 = high
        while (low < high) {
            int mid = low + (high - low) / 2;
            int hour = 0;
            for_each(piles.begin(), piles.end(), [&](int pile) { hour += ceil((double) pile / mid); });

            if (hour <= H) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> piles{3,6,7,11};
    cout << s->minEatingSpeed(piles, 8) << endl;
    return 0;
}
