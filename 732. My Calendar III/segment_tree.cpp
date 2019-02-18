#include <queue>
#include <memory>
#include <iostream>
using namespace std;

struct SegmentTreeNode {
    int start, end, count;                  // count is how many book in range [start, end)
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b, int c): start(a), end(b), count(c), left(nullptr), right(nullptr) {}

    friend ostream& operator<<(ostream& os, const SegmentTreeNode root) {
        os << "[" << root.start << "," << root.end << "]:" << root.count << " ";
        return os;
    }
};

// failed at this test case
class MyCalendarThree {
public:
    MyCalendarThree(): root_(nullptr), mostBook_(0) {
    }
    
    int book(int start, int end) {
        root_ = update(root_, start, end);
        return mostBook_;
    }

    // update the segment tree, also update mostBook_
    SegmentTreeNode* update(SegmentTreeNode* cur, int start, int end) {
        if (start >= end) {
            return cur;
        }
        if (cur == nullptr) {
            if (mostBook_ < 1) {
                mostBook_ = 1;
            }
            return new SegmentTreeNode(start, end, 1);
        }

        if (cur->start >= end) {
            cur->left = update(cur->left, start, end);
        } else if (cur->end <= start) {
            cur->right = update(cur->right, start, end);
        } else {
            int leftStart = min(start, cur->start);
            int rightEnd = max(end, cur->end);
            // update cur to the overlapping segment
            cur->start = max(start, cur->start);
            cur->end = min(end, cur->end);
            if (++cur->count > mostBook_) {
                mostBook_ = cur->count;
            }

            cur->left = update(cur->left, leftStart, cur->start);
            cur->right = update(cur->right, cur->end, rightEnd);
        }
        return cur;
    }

    SegmentTreeNode* root_;
    int mostBook_;                   // maximum number of concurrent ongoing book at any time.
};

void display(SegmentTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << *root << endl;
    display(root->left);
    display(root->right);
}

void levelOrder(SegmentTreeNode* root) {
    if(!root) {
        return;
    }
    queue<SegmentTreeNode*> cur, next;
    cur.push(root);
    while(!cur.empty())
    {
        while(!cur.empty())
        {
            SegmentTreeNode *node = cur.front();
            cur.pop();
            cout << *node;
            if(node->left) {
                next.push(node->left);
            }
            if(node->right) {
                next.push(node->right);
            }
        }
        swap(next,cur);
        cout << endl;
    }
    return;
}



/**
 * Your MyCalendarThree object will be instantiated and called as such:
 
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

int main() {
    MyCalendarThree cal;
    // [1,1,1,1,1,2,2,2,3,3,3,4,5,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7]
    /*
    cout << cal.book(47, 50) << endl;
    cout << cal.book(1, 10) << endl;
    cout << cal.book(27, 36) << endl;
    cout << cal.book(40, 47) << endl;
    cout << cal.book(20, 27) << endl;
    cout << cal.book(15, 23) << endl;
    cout << cal.book(10, 18) << endl;
    cout << cal.book(27, 36) << endl;
    cout << cal.book(17, 25) << endl;
    */

    // [[],[97,100],[51,65],[27,46],[90,100],[20,32],[15,28],[60,73],[77,91],[67,85],[58,72],[74,93],[73,83],[71,87],[97,100],[14,31],[26,37],[66,76],[52,67],[24,43],[6,23],[94,100],[33,44],[30,46],[6,20],[71,87],[49,59],[38,55],[4,17],[46,61],[13,31],[94,100],[47,65],[9,25],[4,20],[2,17],[28,42],[26,38],[72,83],[43,61],[18,35]]
    // [null,1,1,1,2,2,3,3,3,3,3,3,4,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,8,9,9,9,9,9,10]
    cout << cal.book(97,100) << endl;
    cout << cal.book(51,65) << endl;
    cout << cal.book(27,46) << endl;
    cout << cal.book(90,100) << endl;
    cout << cal.book(20,32) << endl;
    cout << cal.book(15,28) << endl;
    cout << cal.book(60,73) << endl;
    cout << cal.book(77,91) << endl;
    cout << cal.book(67,85) << endl;
    cout << cal.book(58,72) << endl;
    cout << cal.book(74,93) << endl;
    cout << cal.book(73,83) << endl;
    cout << cal.book(71,87) << endl;
    cout << cal.book(97,100) << endl;
    cout << cal.book(14,31) << endl;
    cout << cal.book(26,37) << endl;
    cout << cal.book(66,76) << endl;
    cout << cal.book(52,67) << endl;
    cout << cal.book(24,43) << endl;
    cout << cal.book(6,23) << endl;
    cout << cal.book(94,100) << endl;
    cout << cal.book(33,44) << endl;
    cout << cal.book(30,46) << endl;
    cout << cal.book(6,20) << endl;
    cout << cal.book(71,87) << endl;
    cout << cal.book(49,59) << endl;
    cout << cal.book(38,55) << endl;
    cout << cal.book(4,17) << endl;
    cout << cal.book(46,61) << endl;
    cout << cal.book(13,31) << endl;            // 7
    cout << cal.book(94,100) << endl;
    cout << cal.book(47,65) << endl;
    cout << cal.book(9,25) << endl;
    cout << cal.book(4,20) << endl;             // 8
    cout << cal.book(2,17) << endl;             // 9
    cout << cal.book(28,42) << endl;
    cout << cal.book(26,38) << endl;
    cout << cal.book(72,83) << endl;
    cout << cal.book(43,61) << endl;
    cout << cal.book(18,35) << endl;            // 10
    levelOrder(cal.root_);
}
