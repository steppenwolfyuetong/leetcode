// see leetcode 300

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> tail;
        for(int i = 0; i < nums.size(); i++) {
            auto it = std::lower_bound(tail.begin(), tail.end(), nums[i]);
            if (it == tail.end()) {
                tail.push_back(nums[i]);
                if (tail.size() == 3) {
                    return true;
                }
            } else {
                *it = nums[i];
            }
        }
        return false;
    }
};


Apparently, as you may have already noticed, the "dp" here contains at most 2 elements, 
so one instant simplification here is to replace "lower_bound" call to a simple "if comparison else comparison". 
Then a much more simplified version is obtained:

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (auto n : nums)
            if (n <= a)
                a = n;
            else if (n <= b)
                b = n;
            else
                return true;
        return false;
    }
};
