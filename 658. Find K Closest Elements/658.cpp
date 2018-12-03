class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lower = lower_bound(arr.begin(), arr.end(), x);
        auto upper = upper_bound(arr.begin(), arr.end(), x);
        if (upper - lower >= k) {
            return vector<int>(lower, lower + k);
        }
        
        deque<int> result(lower, upper);
        while (result.size() < k) {
            if (lower == arr.begin()) {
                result.push_back(*(upper++));
            } else if (upper == arr.end()) {
                result.push_front(*(--lower));
            } else {
                if ((*upper) - x < x - *(lower - 1)) {
                    result.push_back(*(upper++));
                } else {
                    result.push_front(*(--lower));
                }
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
