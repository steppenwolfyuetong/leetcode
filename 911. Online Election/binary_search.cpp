/*
Input: ["TopVotedCandidate","q","q","q","q","q","q"], 
        [
            [
                [0,1,1,0,0,1,0],                    // votes for person 0,1,1,...
                [0,5,10,15,20,25,30]                // vote at time 0,5,10,...
            ],
            [3],[12],[25],[15],[24],[8]
        ]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
*/

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int n = persons.size(), leader = -1;
        unordered_map<int, int> count;      // person -> vote counts

        for (int i = 0; i < n; ++i) {
            m[times[i]] = persons[i];
        }

        for (auto& it : m) {
            count[it.second]++;
            if (count[it.second] >= count[leader]) {      // as ties go to the most recent vote
                leader = it.second;
            }
            m[it.first] = leader;
        }
    }
    
    int q(int t) {
        return (--m.upper_bound(t))-> second;   // return leader of the last vote time before t
    }
private:
    map<int, int> m;        // time -> leaderer, ordered by time

};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
