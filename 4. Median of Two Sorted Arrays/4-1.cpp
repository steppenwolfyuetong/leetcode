#include "../leetcode.h"

class Solution {
public:
    // Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size() + nums2.size();
        if (sz == 0) throw runtime_error("both empty");
        double m = findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (sz + 1) / 2);
        if (sz % 2 == 0) {
            m = (m + findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (sz + 2) / 2)) / 2.0;
        }
        return m;
    }

    using iter = vector<int>::iterator;
    // find k-th smallest element in merged array nums1[s1, e1) and nums2[s2, e2)
    // invariant: kth element is in range nums1[s1, e1), nums2[s2, e2)
    int findKth(iter s1, iter e1, iter s2, iter e2, int k) {
        if (s1 == e1) {
            return *(s2 + k - 1);
        } else if (s2 == e2) {
            return *(s1 + k - 1);
        }

        if (k == 1) {
            return min(*s1, *s2);
        }

        // find (k/2)-th element in both array, and compare them
        int k1 = min(int(e1 - s1), k / 2);
        int k2 = min(int(e2 - s2), k / 2);
        iter m1 = s1 + k1 - 1;
        iter m2 = s2 + k2 - 1;

        if (*m1 < *m2) {                                    // target can't in nums1[s1, m1]
            return findKth(s1 + k1, e1, s2, e2, k - k1);
        } else {                                            // target can't in nums2[s2, m2]
            return findKth(s1, e1, s2 + k2, e2, k - k2);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,3,5,7}, nums2 = {2,4,6};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
