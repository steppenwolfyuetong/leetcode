#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n, 0);        
        parents_ = vector<int>(n, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        // Meger low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu])
            parents_[pu] = pv;           
        else if (ranks_[pu] > ranks_[pv])
            parents_[pv] = pu;
        else {
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};

// Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFindSet ufs(n);

        // owner save which user has the same email
        map<string, vector<int>> owner;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {      // email start from index 1
                owner[accounts[i][j]].emplace_back(i);
            }
        }
        for (const auto& p : owner) {
            if (p.second.size() > 1) {                          // more than two input has same email, union them
                for (int i = 1; i < p.second.size(); i++) {
                    ufs.Union(p.second[0], p.second[i]);
                }
            }
        }
        
        map<int, set<string>> merged;                           // index -> set of email
        for (int i = 0; i < accounts.size(); i++) {
            int root = ufs.Find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                merged[root].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> result;
        for (const auto& p : merged) {
            result.emplace_back(vector<string>{accounts[p.first][0]});
            for (const auto& email : p.second) {
                result.back().emplace_back(email);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<string>> accounts, result;
    /*
    accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    result = s.accountsMerge(accounts);
    */
    accounts = {
        {"David","David0@m.co","David4@m.co","David3@m.co"},
        {"David","David5@m.co","David5@m.co","David0@m.co"},
        {"David","David1@m.co","David4@m.co","David0@m.co"},
        {"David","David0@m.co","David1@m.co","David3@m.co"},
        {"David","David4@m.co","David1@m.co","David3@m.co"}};
    result = s.accountsMerge(accounts);
    for (int i = 0; i < result.size(); i++) {
        for (const auto& x : result[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

