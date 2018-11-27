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
    void partion(vector<int>&preorder,int start,int end,int &right){	
        int root = preorder[start];
        for(int i = start + 1;i < end;i++){
            if(preorder[i] > root){
                right = i;
                break;
            }
        }
    }
    //[start,end)
    bool verifyPreorderSub(vector<int>&preorder,int start,int end){
        if((end-start) < 2)
            return true;

        int root = preorder[start];

        //divide array into two parts
        int left = start + 1,right = end;
        partion(preorder,start,end,right);

        //check BST property
        for(int i = left;i < right;i++){
            if(preorder[i] > root)
                return false;
        }
        for(int i = right;i < end;i++){
            if(preorder[i] < root)
                return false;
        }
        return verifyPreorderSub(preorder,left,right) && verifyPreorderSub(preorder,right,end);
    }
    /*algorithm brute force
      1)A[0] is root, divide A[1..n] into two parts A[1,right-1] and A[right,n]
      2)check each element A[i] in left tree A[i] < root and each element A[j] in right tree, A[j] > root
      3)recrusive call preorder for child array A[1..,right-1] and A[right,n] 
      time O(n*n) space O(1)
      */

    //和栈的方法类似
    bool verifyPreorder(vector<int>&preorder) {
        return verifyPreorderSub(preorder,0,preorder.size());
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
