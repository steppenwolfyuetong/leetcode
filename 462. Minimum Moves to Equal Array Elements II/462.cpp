class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int i = 0, j = nums.size() - 1;
        int count = 0;
        while(i < j)
        {
            count += nums[j--] - nums[i++];
        }
        return count;
    }

    // O(n).
    // Image the nums are sorted, and the final value is k, we start find k from the first element.
    // If we increase k, the elements <= k will need move one step more, and the elements > k will need to move one step less.
    // If there are more elements > k than elements <= k, we should increase k to minimize the moves.
    // So we just increase k, until k reach the median of of the nums array. By then, the number of elements <= k equals to that of elements > k.
    // (There is a slight different when the number of array is odd, but it's similar).
    // If we keep increasing k after k reach the median of the array, more numbers >k than <= k, and more moves needed, so we should stop.
    //
    // The sort is not needed since we find the k is the median of the array, there is an average O(n) algorithm to find such k.
    // 找到中位数
    int minMoves3(vector<int>& nums) {
        int n = nums.size();
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        int total = 0;
        for (auto &i : nums)
            total += abs(i - median);
        return total;
    }
};
