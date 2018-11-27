#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class TreeNode
{
public:
    TreeNode *next[2];
    TreeNode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

// Use Trie
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int rt = 0;
        TreeNode *root = buildTrie(nums);

        for(auto num : nums)
        {
            rt = max(rt, helper(root, num));
        }
        return rt;
    }

    TreeNode* buildTrie(vector<int> &nums)
    {
        TreeNode *root = new TreeNode(), *cur;
        for(auto num : nums)
        {
            cur = root;
            for(int i = 31; i > -1; i--)
            {
                int index = ((num >> i) & 1);
                if(cur->next[index] == NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }

    // find max XOR result of num with another one
    int helper(TreeNode *cur, int num)
    {
        int rt = 0;
        for(int i = 31; i > -1; i--)
        {
            // try to find the i-th bit is different
            int index = !((num >> i) & 1);
            // there is number that differs from num in i-th bit
            if(cur->next[index])
            {
                rt <<= 1;
                rt |= 1;
                cur = cur->next[index];
            }
            else
            {
                rt <<= 1;
                rt |= 0;
                cur = cur->next[!index];
            }
        }
        return rt;
    }
};

int main()
{
    int arr[] = {3,10,5,25,2,8};
    vector<int> nums;
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        nums.push_back(arr[i]);
    }

    Solution *s = new Solution();
    cout << s->findMaximumXOR(nums) << endl;
}
