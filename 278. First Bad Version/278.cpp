// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // loop invariant: 1 <= target <= n
        int left = 1, right = n;

        // when left + 1 = right, won't loop forever, so left < right is ok, left is the ans
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(!isBadVersion(mid))
                left = mid + 1;     // mid can't be target
            else
                right = mid;        // mid can be target
        }
        return left;
    }
};
