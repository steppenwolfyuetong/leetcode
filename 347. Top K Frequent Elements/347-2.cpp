#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //第二个参数是容器类型（必须是数组实现的容器如vector deque 而不能是list） 
        //第三个参数是比较方法 也可以自己实现一个比较的类 然后重载 <  > 或者 () 实现自定义类型的比较
        //优先队列默认是大顶堆 也就是大者优先级高
        //仿函数greater用于实现小顶堆 less可以实现大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        unordered_map<int, int> cnt;
        for(auto num : nums)
        {
            cnt[num]++;
        }

        for(auto kv : cnt)
        {
            pq.push(make_pair(kv.second,kv.first));			// 优先以出现次数比较 
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> rt;
        while (!pq.empty()) 
        {
            rt.push_back(pq.top().second);
            pq.pop();
        }
        return rt;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);

    Solution s;
    vector<int> rt  = s.topKFrequent(nums, 2);
    for(int i = 0; i < rt.size(); i++)
    {
        cout << rt[i] << ' ';
    }
    cout << endl;
    return 0;
}
