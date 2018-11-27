#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // pq是大小为3的堆 set保存pq中是否有这个数
    int thirdMax(vector<int>& nums) {
        // 最小堆
        priority_queue<int, vector<int>, greater<int> > pq;
        set<int> numSet;
        for(auto num : nums)
        {
            if(!numSet.count(num))
            {
                numSet.insert(num);
                if(pq.size() < 3)
                {
                    pq.push(num);
                }
                else
                {
                    if(num > pq.top())
                    {
                    	numSet.erase(pq.top());
                    	pq.pop();
                        pq.push(num);
                    }
                }
            }
        }
        
        int rt = pq.top();
		if(pq.size() < 3)
		{
			while(!pq.empty())
			{
				rt = pq.top();
				pq.pop();
			}
		}
		return rt;
    }

    // set就是基于红黑树实现的 直接用
    int thirdMax1(vector<int>& nums) {
        set<int> top3;
        for (int num : nums) {
            top3.insert(num);
            if (top3.size() > 3)
                top3.erase(top3.begin());
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};

int main()
{
    vector<int> nums;
    int size = 7;
    int arr[] = {1,2,3,4,5,6,6};
    for(int i = 0; i < size; i++)
    {
        nums.push_back(arr[i]);
    }

    Solution *s = new Solution();
    cout << s->thirdMax(nums) << endl;
    return 0;
}
