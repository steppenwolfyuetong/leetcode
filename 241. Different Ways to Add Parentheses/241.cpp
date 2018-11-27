#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); i++)
        {
            char cur = input[i];
            if(cur == '+' || cur == '-' || cur == '*')
            {
                vector<int> result1 = diffWaysToCompute(input.substr(0,i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
            
	            for(auto res1 : result1)
	            {
	                for(auto res2 : result2)
	                {
	                    if(cur == '+')
	                        result.push_back(res1 + res2);
	                    else if(cur == '-')
	                        result.push_back(res1 - res2);
	                    else
	                        result.push_back(res1 * res2);
	                }
	            }
        	}
        }

        if(result.empty())
        {
            result.push_back(atoi(input.c_str()));
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> result = s.diffWaysToCompute("2*3-4*5");
	for(auto num : result)
		cout << num << ' ' << endl;
	cout << endl;
	return 0;
}
