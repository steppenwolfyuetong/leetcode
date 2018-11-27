#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> table;
        vector<string> bucket(s.size() + 1, "");
        string rt;

        for(auto ch : s)
        {
            table[ch]++;
        }
        for(auto p : table)
        {
            bucket[p.second].append(p.second, p.first);
        }
        for(int i = bucket.size() - 1; i > -1; i--)
        {
            if(!bucket[i].empty())
            {
                rt.append(bucket[i]);
            }
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    string str = "tree";
    cout << s->frequencySort(str) << endl;
    return 0;
}
