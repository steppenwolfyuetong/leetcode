/*
So there are two case.

The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
The second is that the subarray take a part of head array and a part of tail array.

We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.

So the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0;
        int curMax = 0, curMin = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;

        for (int i = 0; i < A.size(); i++) {
            curMax = max(curMax + A[i], A[i]);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + A[i], A[i]);
            minSum = min(minSum, curMin);

            total += A[i];
        }

        // corner case: If all number are negative, return the maximum one, (which equals to the max subarray sum)
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};

