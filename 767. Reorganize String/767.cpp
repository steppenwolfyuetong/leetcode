#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        auto cmp = [](const pair<int, char> &p1, const pair<int,char> &p2) { return p1.first < p2.first; };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> pq(cmp);

        /*
         * 两种写法一样
        struct cmp {
            bool operator()(const pair<int, char> &p1, const pair<int,char> &p2) {
                return p1.first < p2.first;
            }
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        */

        unordered_map<char, int> table;
        for (int i = 0; i < S.size(); i++) {
            table[S[i]]++;
        }

        for (auto& p : table) {
            pq.push(make_pair(p.second, p.first));
        }
        
        string result = "";
        char last = 0;                  // last letter in result
        while (!pq.empty()) {
            pair<int, char> invalid;
            bool flag = false;
            // if last letter's count is biggest, pop it and push back later
            if (pq.top().second == last) {
                invalid = pq.top();
                pq.pop();
                flag = true;
            } 

            // if only has last letter, impossible to reorganize
            if (pq.empty()) {
                return "";
            } else {
                pair<int, char> p = pq.top();
                pq.pop();
                result += p.second;
                last = p.second;
                if (p.first > 1) {
                    pq.push(make_pair(p.first - 1, p.second));
                }
            }

            if (flag) {
                pq.push(invalid);
            }
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->reorganizeString("aaaaabbbccc") << endl;
    return 0;
}
