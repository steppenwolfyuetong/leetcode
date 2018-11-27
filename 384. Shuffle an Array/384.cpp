#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> rt(nums);
        for(int i = rt.size() - 1; i > -1; i--)
        {
            int pos = rand() % (i + 1);
            swap(rt[i], rt[pos]);
        }
        return rt;
    }
private:
    vector<int> nums;
};

void display(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

/*
 * 算法原理：每次选择一个位置，并用随机数求模得到要交换的位置，交换过后，此位置元素已经确定，不再参与交换
 */

int main()
{
    vector<int> nums;
    for(int i = 0; i < 7; i++)
    {
        nums.push_back(i);
    }
    Solution *obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();

    display(param_2);
    return 0;
}
