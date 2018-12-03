class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) {
            return letters.front();
        }

        // What is a loop invariant?
        // a loop invariant is a statement that holds true before the loop and after each iteration.
        // So it must also hold after the loop is terminated
        //
        // loop invariant P: [0, left) <= target & target < [right, letters.length-1]
        // loop termination: right - left decrease after every iteration (make sure the base case left + 1 = right is also true)
        int left = 0, right = letters.size() - 1;

        while (left < right) {      // Q
            int mid = left + (right - left) / 2;
            if (target < letters[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Now P is True and Q is false
        // Becuase left > right is impossible, we know that l == r
        // Thus left/right is the answer
        return letters[left];
    }
};
