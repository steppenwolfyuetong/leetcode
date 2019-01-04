/*
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/

/*
 *  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103066/Ideas-behind-the-O(n)-two-pass-and-one-pass-solutions
 *  1. If we sort nums, the ans is length of nums[i,j] that i is the first nums[i] != sorted[i] and j is the last nums[j] != sorted[j]
 *  2. It turns out that the two boundary indices i and j can be found in linear time, if we take advantage of the following three properties:
 *      * nums[0, i - 1] and nums[j + 1, n - 1] are both sorted.
 *      * nums[i] != sorted[i] and nums[j] != sorted[j].
 *      * nums[i - 1] <= min and max <= nums[j + 1], where min and max are the minimum and maximum values of subarray nums[i, j].
 *     
 *      Since we aim at the shortest subarrays, from the first property alone, we need to find the two longest sorted subarrays starting at index 0 and ending at index n - 1, respectively. Assume the two subarrays are nums[0, l] and nums[r, n - 1]. If there is overlapping between these two subarrays, i.e.l >= r, then the whole array is sorted so 0 will be returned. Otherwise, the input array is not sorted. However, we cannot say sorting nums[l, r] will leave the whole array sorted, because at this moment the third property may not be satisfied.
 *      To guarantee the third property, assume min and max are the minimum and maximum values of subarray nums[l, r], then we need to decrease l as long as nums[l] > min, and increase r as long as nums[r] < max. After this is done, it can be shown that the second property will be met automatically, and nums[l + 1, r - 1] will be the shortest subarray we are looking for (that is, i = l + 1 and j = r - 1).
 *
 */

class Solution {
public:
    // O(nlogn)
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());        
        sort(sorted.begin(), sorted.end());

        int i = 0, j = nums.size() - 1;
        while (i < nums.size() && nums[i] == sorted[i]) {
            i++;
        }
        while (i < j && nums[j] == sorted[j]) {
            j--;
        }

        return j - i + 1;
    }

    // O(n), two pass
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r && nums[l] <= nums[l + 1]) l++;
            
        if (l >= r) return 0;
        
        while (nums[r] >= nums[r - 1]) r--;
        
        int maxEle = INT_MIN, minEle = INT_MAX;
            
        // maxEle and minEle is the max and min in range of nums[l, r]
        for (int k = l; k <= r; k++) {
            maxEle = Math.max(maxEle, nums[k]);
            minEle = Math.min(minEle, nums[k]);
        }
        
        // enlarge the range to make if nums[l,r] is sorted, the whole array is sorted.
        while (l >= 0 && minEle < nums[l]) l--;
        while (r < nums.length && nums[r] < maxEle) r++;
            
        return (r - l - 1);
    }

};
