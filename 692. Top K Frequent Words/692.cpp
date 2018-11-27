#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> table;
        for(string word : words)
        {
            table[word]++;
        }

        //自定义可调用的函数操作符的对象
        //priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        //匿名函数
        auto lambdaCmp = [](pair<int, string> &kv1, pair<int, string> &kv2) {
            return kv1.first > kv2.first || (kv1.first == kv2.first && kv1.second < kv2.second);
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(lambdaCmp)> pq(lambdaCmp);

        for(auto kv : table)
        {
            pq.push(make_pair(kv.second, kv.first));
            if(pq.size() > k)
                pq.pop();
        }

        vector<string> rt;
        while(!pq.empty())
        {
            //cout << pq.top().first << ':' << pq.top().second << endl;
            rt.push_back(pq.top().second);
            pq.pop();
        }
        reverse(rt.begin(), rt.end());
        return rt;
    }
private:
    struct cmp
    {
        bool operator()(const pair<int, string> &kv1, const pair<int, string> &kv2)
        {
            // kv.first越小优先级越高
            // kv.first优先级相同时 kv.second字母排序越靠前 优先级越高
            // 本来应该是kv1.second > kv2.second 但输出前会再逆序一下 所以这里返回kv1.second < kv2.second
            if(kv1.first > kv2.first)
            {
                return true;
            }
            else if(kv1.first < kv2.first)
            {
                return false;
            }
            else
            {
                return kv1.second < kv2.second;
            }
        }
    };
};


void display(vector<string> words)
{
    for(string word : words)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    vector<string> words1{"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> words2{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k1 = 2, k2 = 4;

    Solution *s = new Solution();

    display(s->topKFrequent(words1, k1));
    display(s->topKFrequent(words2, k2));

    return 0;
}
