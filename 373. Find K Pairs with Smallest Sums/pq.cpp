#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > rt;
        if(nums1.empty() || nums2.empty() || k < 1)
        {
            return rt;
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;      // 最小堆
        for(int i = 0; i < min((int)nums1.size(), k); i++)
        {
            for(int j = 0; j < min((int)nums2.size(), k); j++)
            {
                if(pq.size() < k)
                {
                    pq.push(make_pair(nums1[i], nums2[j]));
                }
                else if(nums1[i] + nums2[j] < pq.top().first + pq.top().second)
                {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        while(!pq.empty())
        {
            rt.push_back(pq.top());
            pq.pop();
        }
        return rt;
    }

private:
    struct compare
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first + a.second < b.first + b.second;
        }
    };
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    int a[] = {1,1,5};
    int b[] = {1,2,3};
    for(int i = 0; i < 3; i++)
    {
        nums1.push_back(a[i]);
        nums2.push_back(b[i]);
    }

    Solution *s = new Solution();
    int k = 3;
    vector<pair<int, int> > rt = s->kSmallestPairs(nums1, nums2, k);
    for(int i = 0; i < rt.size(); i++)
    {
        cout << rt[i].first << ' ' << rt[i].second << endl;
    }
    return 0;
}
