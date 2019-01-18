#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }

        map<int, int> seq;                  // {k, v}: subsequences ends with k -> count of subsequences ends with k
        for (const auto& num : nums) {
            if (freq[num] <= 0) {
                continue;
            }

            if (seq[num - 1] > 0) {                             // add num to a subsequence end with num - 1
                seq[num - 1]--, seq[num]++;
                freq[num]--;
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {        // if can start a new subsequence
                seq[num + 2]++;
                freq[num]--, freq[num + 1]--, freq[num + 2]--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {1,2,3,3,4,4,5};
    cout << s->isPossible(nums) << endl;
    return 0;
}
