/*
Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

*/

class Solution {
public:
    // dfs
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> hash;   // ppid -> vector<pid>
        vector<int> ret;

        for(int i = 0; i < pid.size(); ++i)
            hash[ppid[i]].push_back(pid[i]);

        killAll(kill, hash, ret);

        return ret;
    }

    void killAll(int kill, unordered_map<int, vector<int>>& hash, vector<int>& ret) {
        ret.push_back(kill);
        for(auto id : hash[kill]) 
            killAll(id, hash, ret);
    }

    // bfs
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> hash;   // ppid -> vector<pid>
        queue<int> que;
        vector<int> ret;

        for(int i = 0; i < pid.size(); ++i)
            hash[ppid[i]].push_back(pid[i]);

        que.push(kill);
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; ++i) {
                int cur = que.front();
                que.pop();
                ret.push_back(cur);
                for(auto id : hash[cur]) 
                    que.push(id);
            }
        }

        return ret;
    }
}

