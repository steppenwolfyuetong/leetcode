#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    	if(envelopes.empty())
    		return 0;
    	
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp(envelopes.size(), 1);
        int rt = 1;

        for(int i = 0; i < envelopes.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            
            rt = max(rt, dp[i]);
        }
        return rt;
    }
};

int main()
{
    //[[5,4],[6,4],[6,7],[2,3]]
    vector<pair<int, int> > env;
    env.push_back(make_pair(5,4));
    env.push_back(make_pair(6,4));
    env.push_back(make_pair(6,7));
    env.push_back(make_pair(2,3));
    
    Solution s;
    cout << s.maxEnvelopes(env) << endl;
}
