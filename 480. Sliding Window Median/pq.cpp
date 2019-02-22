#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> median;
        unordered_map<int, int> table;
        priority_queue<int> maxHeap(nums.begin(), nums.begin() + k);            //最大堆 保存较小部分的数
        priority_queue<int, vector<int>, greater<int> > minHeap;                //最小堆 保存较大部分的数

        while(maxHeap.size() - minHeap.size() > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        for(int i = k; i < nums.size() + 1; i++)
        {
            if(k % 2)
                median.push_back(maxHeap.top() / 1.0);
            else
                median.push_back(((double)maxHeap.top() + (double)minHeap.top()) / 2.0);        //防止溢出
            
            if(i == nums.size())
                break;

            int numToAdd = nums[i];
            int numToDelete = nums[i - k];
            int balance = 0;

            //判断要删除的数在哪个堆
            if(numToDelete <= maxHeap.top())
            {
                balance -= 1;
                if(maxHeap.top() == numToDelete)
                    maxHeap.pop();
                else
                    table[numToDelete] += 1;            //标记 直到该数为堆顶的时候再删除
            }
            else
            {
                balance += 1;
                if(minHeap.top() == numToDelete)
                    minHeap.pop();
                else
                    table[numToDelete] += 1;            //标记 直到该数为堆顶的时候再删除
            }

            // balance = -2/0/2
            if(!maxHeap.empty() && numToAdd <= maxHeap.top())
            {
                balance += 1;
                maxHeap.push(numToAdd);
            }
            else
            {
                balance -= 1;
                minHeap.push(numToAdd);
            }

            // rebalance
            if(balance > 0)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(balance < 0)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // 删除堆顶且有标记的元素
            while(!maxHeap.empty() && table[maxHeap.top()] > 0)
            {
                table[maxHeap.top()] -= 1;
                maxHeap.pop();
            }
            while(!minHeap.empty() && table[minHeap.top()] > 0)
            {
                table[minHeap.top()] -= 1;
                minHeap.pop();
            }
        }
        return median;
    }
};

int main()
{
    Solution *s = new Solution();
    int arr[] = {1,3,-1,-3,5,3,6,7};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<double> rt = s->medianSlidingWindow(nums, 3);
    for(auto median : rt)
        cout << median << endl;
    return 0;
}
