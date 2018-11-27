/*
Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
*/


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = 0;
        double sum = 0;
        int len = k;
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        maxavg = sum/k;
        double avg = maxavg;
        
        for(int i = k; i < nums.size(); i++)
        {
            len++;
            sum += nums[i];
            avg = sum/len;
            
            double tempsum = sum;
            double tempavg = avg;
            for(int j = len - 1; j >= k; j--)
            {
                tempsum -= nums[i - j];
                tempavg = tempsum / j;
                if(tempavg >= avg)
                {
                    avg = tempavg;
                    sum = tempsum;
                    len = j;
                }
            }
            if(avg > maxavg)
                maxavg = avg;
        }
        return maxavg;
    }
};
