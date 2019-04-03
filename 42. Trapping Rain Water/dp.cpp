class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int ans = 0;
        int size = height.size();
        // the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height 
        // of bars on both the sides minus its own height.
        // 
        // so we save left sides maximum height in left_max, right sides maximum height in right_max
        //
        // left_max[i] is max bar in range [0,i], right_max[i] is max bar in range [i, ]
        vector<int> left_max(size), right_max(size);        

        // search from left to right
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }

        // searhch from right to left
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }

        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
