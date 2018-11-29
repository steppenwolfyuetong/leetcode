#include <deque>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    // TLE, the idea is ok
    // we don't need lastTask actually, we can add n + 1 tasks in a time instead of adding one task each time.
    // see pq-1.cpp
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
        deque<char> lastTask;                  // last n task
        while (!pq.empty()) {
            vector<pair<char, int>> invalid;
            while (!pq.empty() && find(lastTask.begin(), lastTask.end(), pq.top().first) != lastTask.end()) {
                invalid.push_back(pq.top());
                pq.pop();
            }

            if (pq.empty()) {
                lastTask.push_back('0');             // no valid task exists, push '0' to represent idle inteval
            } else {
                pair<char, int> nextTask = pq.top();
                pq.pop();
                lastTask.push_back(nextTask.first);
                if (nextTask.second > 1) {
                    pq.push(make_pair(nextTask.first, nextTask.second - 1));
                }
            }

            result++;
            if (lastTask.size() > n) {
                lastTask.pop_front();
            }

            for (auto& task : invalid) {
                pq.push(task);
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
    vector<char> tasks{'A','A','A','B','B','B'};
    cout << s->leastInterval(tasks, 2) << endl;
    return 0;
}
