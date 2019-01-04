class Solution {
public:
    // Bidirectional BFS improves the efficiency
    // also use unordered_set instead of queue
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000") || dead.count(target)) {
            return -1;
        }

        unordered_set<string> visited;
        visited.insert("0000");
        unordered_set<string> q1, q2;
        q1.insert("0000");
        q2.insert(target);

        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            unordered_set<string> temp;                 // store next keys
            for (auto& key : q1) {
                if (q2.count(key)) {
                    return step;
                }
                if (dead.count(key)) {
                    continue;
                }
                dead.insert(key);                       // update deadends to prevent visit again
                
                for (int i = 0; i < 4; i++) {
                    string tmp = key;
                    tmp[i] = (key[i] - '0' + 1) % 10 + '0';
                    temp.insert(tmp);
                    tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
                    temp.insert(tmp);
                }
            }
            step++;
            swap(q1, q2);
            swap(q2, temp);
        }
        return -1;
    }
};

