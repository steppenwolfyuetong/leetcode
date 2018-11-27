/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Follow up:
Could you do it using only constant space complexity?
*/

#include <stack>
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    //stack
/*
 * Kinda simulate the traversal, keeping a stack of nodes (just their values) of which we're still in the left subtree. 
 * If the next number is smaller than the last stack value, then we're still in the left subtree of all stack nodes, so just push the new one onto the stack. 
 * But before that, pop all smaller ancestor values, as we must now be in their right subtrees (or even further,
 * in the right subtree of an ancestor). Also, use the popped values as a lower bound,
 * since being in their right subtree means we must never come across a smaller number anymore.
 */
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size() < 2)
            return true;

        stack<int> stk;
        stk.push(preorder[0]);
        int parent = INT_MIN;
        for(int i = 1; i < preorder.size(); i++)
        {
            if(stk.empty() || preorder[i] < stk.top())
            {
                if(preorder[i] < parent)
                    return false;
                stk.push(preorder[i]);
            }
            else
            {
                while(!stk.empty() && stk.top() < preorder[i])
                {
                    parent = stk.top();
                    stk.pop();
                }
                stk.push(preorder[i]);
            }
        }
        return true;
    }
};

int main()
{
    int array[] = {6,3,1,2,5,4,7};
    int size = sizeof(array) / sizeof(int);
    vector<int> pre(array, array + size);
    Solution s;
    cout << s.verifyPreorder(pre) << endl;
}
