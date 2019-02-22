/*
Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. Return an array of the k digits.
Note: You should try to optimize your time and space complexity.

nums1: 3465     ->  3465    ->  3465 -> ... -> null
nums2: 812593   ->  12593   ->  3    -> ... -> null
k: 7            ->  6       ->  5    -> ... -> 0
result:         ->  8       ->  89   -> ... -> 8933465

Since with more digits, the numbers comes bigger. So the result must be k digits.

1. select max next element which satisfy the length demand. For example, with first digit, we can't choose 9 from nums2, otherwise,
   it can only from result with 6 digits.
2. go to next sub problem

*/

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        if (k <= 0) {
            return result;
        }

        int start1 = 0, start2 = 0;
        while (k) {
            // calculate the end position 
            // for example, the length of remaining nums2 is nums2.size() - start2, 
            // so length of remaining num1 is at least is k - (nums2.size() - start2)
            int end1 = min(nums1.size() - (k - (nums2.size() - start2)) + 1, nums1.size());
            int end2 = min(nums2.size() - (k - (nums1.size() - start1)) + 1, nums2.size());

            if (start1 >= end1) {
                int max2 = maxElement(nums2, start2, end2);
                start2 = max2 + 1;
                result.push_back(nums2[max2]);
            } else if (start2 >= end2) {
                int max1 = maxElement(nums1, start1, end1);
                start1 = max1 + 1;
                result.push_back(nums1[max1]);
            } else {
                int max1 = maxElement(nums1, start1, end1);
                int max2 = maxElement(nums2, start2, end2);

                // choose one
                if (nums1[max1] > nums2[max2]) {
                    start1 = max1 + 1;
                    result.push_back(nums1[max1]);
                } else if (nums1[max1] < nums2[max2]) {
                    start2 = max2 + 1;
                    result.push_back(nums2[max2]);
                } else {
                    // wtf... can't decide which to choose...
                    // depends on sub problems
                    // that is which next valid element is bigger
                }
            }
            k--;
        }
        return result;
    }

    // return the index of max element in nums[start, end)
    int maxElement(vector<int> &nums, int start, int end) {
        return max_element(nums.begin() + start, nums.begin() + end) - nums.begin();
    }
};

int main() {
    Solution *s = new Solution();
    /*
    vector<int> nums1{3,4,6,5};
    vector<int> nums2{8,1,2,5,9,3};
    vector<int> result = s->maxNumber(nums1, nums2, 7);
    */
    vector<int> nums1{3,9};
    vector<int> nums2{8,9};
    vector<int> result = s->maxNumber(nums1, nums2, 3);

    for (auto& num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
