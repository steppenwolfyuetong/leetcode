#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 * For each move, you could choose any m (1 ≤ m ≤ n) washing machines,
 * and pass one dress of each washing machine to one of its adjacent washing machines at the same time .
 */

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if(sum % machines.size())
            return -1;

        int avg = sum / machines.size(), ballance = 0, moves = 0;
        for(auto i = 0; i < machines.size(); i++)
        {
            ballance += machines[i] - avg;
            moves = max(moves, max(machines[i] - avg, abs(ballance)));
        }
        return moves;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> machines{1,0,5};
    cout << s->findMinMoves(machines) << endl;
    return 0;
}
