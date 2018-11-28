/*
 *  initial state:
 *  .   L   .   R   .   .   .   L   R   .   .   L   .   .
 *
 *  two pass:
 *  pass from left to right, count distance of last R, R[i]
 *  0   0   0   0   1   2   3   0   0   1   2   0   0   0
 *  pass right to left, count distance of last L, L[i]
 *  1   0   0   0   3   2   1   0   0   2   1   0   0   0
 *
 *  1. if both of L[i],R[i] equals 0, which means it won't be effected only by L or R, remain the initial state
 *  2. if one of L[i],R[i] equals 0, which means it will be effected only by the one not equals to 0
 *  3. if neither of L[i], R[i] equals[0]:
 *          if L[i] < R[i], which means it needs less time for L, so it will become L
 *          if R[i] < L[i], which means it needs less time for be R, so it will become R
 *          if R[i] = L[i], which means it needs equal time for L and R, so it will become .
 *
 *  final state:
 *  L   L   .   R   R   .   L   L   R   R   L   .   .   .     
 *  
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, 0), right(n, 0);

        bool hasR = false;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                hasR = true;
            } else if (dominoes[i] == '.' && hasR) {
                right[i] = right[i-1] + 1;
            } else {
                hasR = false;
            }
        }

        bool hasL = false;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                hasL = true;
            } else if (dominoes[i] == '.' && hasL) {
                left[i] = left[i+1] + 1;
            } else {
                hasL = false;
            }
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (left[i] == 0 && right[i] == 0) {
                result += dominoes[i];
            } else if (left[i] == 0) {
                result += 'R';
            } else if (right[i] == 0) {
                result += 'L';
            } else {
                if (left[i] < right[i]) {
                    result += 'L';
                } else if (left[i] > right[i]) {
                    result += 'R';
                } else {
                    result += '.';
                }
            }
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    s->pushDominoes(".L.R...LR..L..");
    return 0;
}
