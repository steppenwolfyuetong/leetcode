#include <memory>
#include <iostream>
using namespace std;

struct SegmentTreeNode {
    int start, end, count;                  // count is how many book in range [start, end)
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b, int c): start(a), end(b), count(c), left(nullptr), right(nullptr) {}

};

ostream& operator<<(ostream& os, SegmentTreeNode* root) {
    os << "[" << root->start << "," << root->end << "] " << root->count;
    return os;
}

class MyCalendarTwo {
public:
    MyCalendarTwo(): root_(nullptr) {
    }
    
    bool book(int start, int end) {
        if (query(root_, start, end) >= 2) {
            return false;
        }
        root_ = update(root_, start, end);
        return true;
    }
private:
    // update 
    SegmentTreeNode* update(SegmentTreeNode* cur, int start, int end) {
        if (start >= end) {
            return cur;
        }
        if (cur == nullptr) {
            return new SegmentTreeNode(start, end, 1);
        }

        if (cur->start >= end) {
            cur->left = update(cur->left, start, end);
        } else if (cur->end <= start) {
            cur->right = update(cur->right, start, end);
        } else {
            /*
             *       a -----------------------------b
             *       |              c---------------------------d
             *       |              |               |           |               
             *       |              |               |           |               
             *       |              |               |           |               
             *       leftStart      curStart       curEnd     rightEnd
             *       |     left     |     cur       |   right   |
             */
            int leftStart = min(start, cur->start);
            int rightEnd = max(end, cur->end);
            // update cur to the overlapping segment
            cur->start = max(start, cur->start);
            cur->end = min(end, cur->end);
            cur->count++;

            cur->left = update(cur->left, leftStart, cur->start);
            cur->right = update(cur->right, cur->end, rightEnd);
        }
        return cur;
    }

    // return how many book in this range
    int query(SegmentTreeNode* root, int start, int end) {
        if (root == nullptr || start >= end) {
            return 0;
        }    
        if (root->start >= end) {
            return query(root->left, start, end);
        } else if (root->end <= start) {
            return query(root->right, start, end);
        } else {                                                // overlaps with root
            return max(root->count, max(query(root->left, start, end), query(root->right, start, end)));
        }
    }
public:
    SegmentTreeNode* root_;
};

void display(SegmentTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root << endl;
    display(root->left);
    display(root->right);
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

int main() {
    MyCalendarTwo cal;
    cout << cal.book(47, 50) << endl;
    cout << cal.book(1, 10) << endl;
    cout << cal.book(27, 36) << endl;
    cout << cal.book(40, 47) << endl;
    cout << cal.book(20, 27) << endl;
    cout << cal.book(15, 23) << endl;
    cout << cal.book(10, 18) << endl;
    cout << cal.book(27, 36) << endl;
    cout << cal.book(17, 25) << endl;
    display(cal.root_);
}

