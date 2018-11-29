/*
 * In order to represent a path, I used a combination of 3 variables:
 * int bitMask: mask of all the nodes we visited so far: 0 -> not visited, 1 -> visited (Originally this was Set<Integer>of all nodes we visited so far, but since the Solution TLE and N <= 12, it turns out we can use a bitMask and 32 bits total in an Integer can cover all the possibilities. This is a small speed up optimization.)
 * int curr: current node we are on
 * int cost: the total cost in the path.
 *
 * Each path taken will have a unique combination of these 3 variables.
 */

#include <bitset>
#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<Path> que;
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            int bit = (1 << i);
            que.push(Path(bit, i, 0));
        }

        while (!que.empty()) {
            Path p = que.front();
            que.pop();

            // all nodes visited
            if (p.bitMask == (1 << n) - 1) {
                return p.cost;
            }

            for (auto& neighbor : graph[p.curr]) {
                Path next(p.bitMask | (1 << neighbor), neighbor, p.cost + 1);
                if (visited.find(next) == visited.end()) {
                    que.push(next);
                    visited.insert(next);
                }
            }
        }
        return -1;
    }

private:
    class Path {
    public:
        int bitMask;
        int curr;
        int cost;

        Path(int bitMask, int curr, int cost) {
            this->bitMask = bitMask;
            this->curr = curr;
            this->cost = cost;
        }

        friend ostream& operator<<(ostream &out, const Path &path){
            out << (bitset<8>) path.bitMask << " " << path.curr << " " << path.cost;
            return out;
        }

    };

    struct PathHash {
        size_t operator()(const Path& path) const {
            return 97 * path.bitMask + 71 * path.curr;
        }
    };

    struct PathComp {
        bool operator()(const Path& p1, const Path &p2) const {
            return (p1.bitMask == p2.bitMask) && (p1.curr == p2.curr);
        }
    };
    /*
        template <   
                    class Key,                        // unordered_set::key_type/value_type
                    class Hash = hash<Key>,           // unordered_set::hasher
                    class Pred = equal_to<Key>,       // unordered_set::key_equal
                    class Alloc = allocator<Key>      // unordered_set::allocator_type
        > class unordered_set;
    */
    unordered_set<Path, PathHash, PathComp> visited;
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> graph{vector<int>{1},vector<int>{0,2,4},vector<int>{1,3,4},vector<int>{2},vector<int>{1,2}};
    //vector<vector<int>> graph{vector<int>{1},vector<int>{0,2},vector<int>{1}};
    cout << s->shortestPathLength(graph) << endl;
    return 0;
}

