#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //�ڶ����������������ͣ�����������ʵ�ֵ�������vector deque ��������list�� 
        //�����������ǱȽϷ��� Ҳ�����Լ�ʵ��һ���Ƚϵ��� Ȼ������ <  > ���� () ʵ���Զ������͵ıȽ�
        //���ȶ���Ĭ���Ǵ󶥶� Ҳ���Ǵ������ȼ���
        //�º���greater����ʵ��С���� less����ʵ�ִ󶥶�
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        unordered_map<int, int> cnt;
        for(auto num : nums)
        {
            cnt[num]++;
        }

        for(auto kv : cnt)
        {
            pq.push(make_pair(kv.second,kv.first));			// �����Գ��ִ����Ƚ� 
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
