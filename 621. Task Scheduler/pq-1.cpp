#include <deque>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        unordered_map<char, int> table;
        for (auto& task : tasks) {
            table[task]++;
        }
        for (auto& p : table) {
            pq.push(make_pair(p.first, p.second));
        }
        
        int result = 0;
        while (!pq.empty()) {
            // add n + 1 tasks in each time, none of them are the same
            // if not enough tasks in pq, then add idle interval
            int k = n + 1;
            vector<pair<char, int>> used;
            while (!pq.empty() && k > 0) {
                pair<char, int> task = pq.top();
                pq.pop();
                if (task.second > 1) {
                    used.push_back(make_pair(task.first, task.second - 1));
                }
                result++;
                k--;
            }

            for (auto& task : used) {
                pq.push(task);
            }

            if (pq.empty()) {
                break;              // if not anymore task, we need to break to prevent add k.
            }
            result += k;            // need to be idle for k intervals
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
    vector<char> tasks{'A','A','A','B','B','B'};
    cout << s->leastInterval(tasks, 2) << endl;
    return 0;
}
