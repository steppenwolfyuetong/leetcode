#include<stack>
#include<vector>
#include<iostream>
using namespace std;

// http://blog.csdn.net/doc_sgl/article/details/11805519

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> stk;
        height.push_back(0);
        int result = 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(stk.empty() || height[i] > height[stk.top()])
                stk.push(i);
            else
            {
                int temp = stk.top();
                stk.pop();
                result = max(result, height[temp] * (stk.empty() ? i : i - stk.top() - 1));
				i--;
            }
        }
		return result;
    }
};

int main()
{
    Solution *s = new Solution;
    vector<int> a;
    int height[] = {2,1,5,6,2,3};
    for(int i = 0; i < 6; i++)
        a.push_back(height[i]);
    cout<<s->largestRectangleArea(a)<<endl;
    return 0;
}
