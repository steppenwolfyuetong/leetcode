/*
 *  322  -> 299
 *  10   -> 9
 *  1432 -> 1399
 *  120  -> 119
 *
 *  253761 -> 253759 -> 253699 -> 249999
 *        1<6       5<7        3<5
 *
 *  from LSB to MSB, keep find decreasing, decrease the MSB, fill remaining digits with 9
 */

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string target = to_string(N);

        int inverse = target.size();
        for (int i = target.size() - 1; i > 0; i--) {
            if (target[i] < target[i - 1]) {
                inverse = i;
                target[i - 1] -= 1;
            }
        }

        for (int i = inverse; i < target.size(); i++) {
            target[i] = '9';
        }
        return stoi(target);
    }
};
