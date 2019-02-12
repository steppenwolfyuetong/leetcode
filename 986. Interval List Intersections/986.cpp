#include <vector>
#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;    
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int start = max(A[i].start, B[j].start);
            int end = min(A[i].end, B[j].end);
            if (start <= end) {             // A[i] and B[j] has intersection
                result.emplace_back(start, end);
                //cout << "Interval:" << start << " " << end << endl;
            }
            if (A[i].end < B[j].end) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<Interval> A = {Interval(0,2), Interval(5,10), Interval(13,23), Interval(24,25)};
    vector<Interval> B = {Interval(1,5), Interval(8,12), Interval(15,24), Interval(25,26)};
    s.intervalIntersection(A,B);

    // [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    return 0;
}
