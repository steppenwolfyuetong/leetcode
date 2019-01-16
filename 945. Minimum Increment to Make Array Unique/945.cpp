class Solution {
public:
    // First sort. Compared with previous number, the current number need to be at least prev + 1.
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int count = 0, need = 0;
        for (const auto& num : A) {
            count += max(need - num, 0);
            need = max(need, num) + 1;
        }
        return count;
    }

    int minIncrementForUnique(vector<int>& A) {
        int moves = 0;
        map<int, int> ordered;

        for(auto &i : A){
            ordered[i]++;
        }

        for(auto &i : ordered){
            if(i.second > 1){
                ordered[i.first + 1] = ordered[i.first + 1] + i.second - 1;
                moves += i.second - 1;
            }
        }

        return moves;
    }
};
