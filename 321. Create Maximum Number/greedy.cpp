/*
In short we can first solve 2 simpler problem
Create the maximum number of one array
Create the maximum number of two array using all of their digits.
*/

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result;
        for (int i = max(0, k - n); i <= min(m, k); i++) {
            vector<int> candidate = merge(move(maxArray(nums1, i)), move(maxArray(nums2, k - i)), k);
            result = max(result, candidate);
        }
        return result;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            result.push_back(cmp(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]);
        }

        while (i < nums1.size()) {
            result.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            result.push_back(nums2[j++]);
        }

        return result;
    }

    bool cmp(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    // create maximum number with one array of specific size
    vector<int> maxArray(vector<int> &nums, int size) {
        vector<int> result;
        int len = size;
        int start = 0, end = nums.size() - len + 1;
        while (result.size() < size) {
            int index = max_element(nums.begin() + start, nums.begin() + end) - nums.begin();
            result.push_back(nums[index]);
            len--;
            start = index + 1;
            end = nums.size() - len + 1;
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    /*
    vector<int> nums1{3,4,6,5};
    vector<int> nums2{8,1,2,5,9,3};
    vector<int> result = s->maxNumber(nums1, nums2, 7);

    vector<int> nums1{3,9};
    vector<int> nums2{8,9};
    vector<int> result = s->maxNumber(nums1, nums2, 3);
    */

    vector<int> nums1{6, 7};
    vector<int> nums2{6, 0, 4};
    vector<int> result = s->maxNumber(nums1, nums2, 5);

    for (auto& num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
