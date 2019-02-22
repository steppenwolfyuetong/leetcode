#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (cache_.find(input) != cache_.end()) {
            return cache_[input];
        }

        vector<int> result;
        for (int i = 0; i < input.size(); i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
            
	            for (auto res1 : result1) {
	                for (auto res2 : result2) {
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

        if (result.empty()) {
            result.push_back(stoi(input));
        }

        cache_[input] = result;
        return result;
    }
private:
    unordered_map<string, vector<int>> cache_;
};

int main()
{
	Solution s;
	vector<int> result = s.diffWaysToCompute("2-1-1");
	for(auto num : result)
		cout << num << ' ' << endl;
	cout << endl;
	return 0;
}
