#include <deque>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    string rearrangeString(string str, int k) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        unordered_map<char, int> table;
        for (auto& ch : str) {
            table[ch]++;
        }
        for (auto& p : table) {
            pq.push(make_pair(p.first, p.second));
        }

        string result = "";
        while (!pq.empty()) {
            int n = k;
            vector<pair<char, int>> used;
            while (!pq.empty() && n > 0) {
                pair<char, int> p = pq.top();
                pq.pop();
                if (p.second > 1) {
                    used.push_back(make_pair(p.first, p.second - 1));
                }
                result += p.first;
                n--;
            }

            if (n > 0) {
                return "";
            }

            for (auto& p : used) {
                pq.push(p);
            }
        }
        return result;
    }
    
    struct cmp {
        bool operator()(const pair<char, int>& p1, const pair<char,int>& p2) {
            return p1.second < p2.second;
        }
    };
};

int main() {
    Solution *s = new Solution();
    cout << s->rearrangeString("aabbcc", 3) << endl;
    cout << s->rearrangeString("aaabc", 3) << endl;
    cout << s->rearrangeString("aaadbbcc", 2) << endl;
    return 0;
}
