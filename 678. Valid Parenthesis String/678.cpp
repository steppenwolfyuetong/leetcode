class Solution {
public:
    bool checkValidString(string s) {
        int min_op = 0;                         // min possible open '('
        int max_op = 0;                         // max possible open '('
        
        for (char c : s) {
            if (c == '(') {
                ++min_op;
            } else {
                --min_op;
            }

            if (c == ')') {
                --max_op;
            } else {
                ++max_op;
            }

            if (max_op < 0) {
                return false;
            }

            min_op = max(0, min_op);
        }
        
        return min_op == 0;
    }
};

// same version, easier to understand
/*
   public boolean checkValidString(String s) {
        int low = 0;
        int high = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                low++;
                high++;
            } else if (s.charAt(i) == ')') {
                if (low > 0) {
                    low--;
                }
                high--;
            } else {
                if (low > 0) {
                    low--;
                }
                high++;
            }
            if (high < 0) {
                return false;
            }
        }
        return low == 0;
    }
*/
