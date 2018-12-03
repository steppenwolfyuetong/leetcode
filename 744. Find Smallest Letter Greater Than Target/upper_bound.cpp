/*
 * implement a std::upper_bound
 * this problem can use upper_bound directly
 *
 * auto it = upper_bound(letters.begin(), letters.end(), target);
 * return it == letters.end() ? letters.front() : *it;
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (lettes.back() <= target) {
            return letters.front();
        }

        int low = 0, high = letters.size() - 1;
        // loop invariant: with result is the next greatest letter of target, low <= target <= high
        // we need to handle high = low + 1, according to the if-else statement, it won't loop forever
        while (low < high) {
            int mid = (low + high) / 2;
            if (target < letters[mid]) {
                high = mid;                 // high can be the result, so high = mid
            } else {
                low = mid + 1;              // mid can't be the result, so low = mid + 1
            }
        }
        return letter[left];
    }
};
