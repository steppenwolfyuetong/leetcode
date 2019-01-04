class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                vector<string> nextKeys = move(nextKey(cur));
                for (auto& key : nextKeys) {
                    if (key == target) {
                        return ++step;
                    }
                    if (visited.count(key) || dead.count(key)) {
                        continue;
                    } else {
                        q.push(key);
                        visited.insert(key);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    vector<string> nextKey(string key) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
        }
        return res;
    }
};

