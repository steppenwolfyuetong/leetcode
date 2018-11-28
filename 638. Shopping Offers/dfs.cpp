/*
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation:
There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B.
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
*/

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs, 0);
    }

private:
    // index is the next special offers tries to use
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int index) {
        int minPrice = buyDirectly(price, needs);
        for (int offerIndex = 0; offerIndex < special.size(); offerIndex++) {
            vector<int> offer = special[offerIndex];
            vector<int> updatedNeeds;
            for (int i = 0; i < needs.size(); i++) {
                if (offer[i] > needs[i]) {
                    updatedNeeds.clear();
                    break;
                } else {
                    updatedNeeds.push_back(needs[i] - offer[i]);
                }
            }

            if (!updatedNeeds.empty()) {
                minPrice = min(minPrice, special[offerIndex].back() + dfs(price, special, updatedNeeds, offerIndex + 1));
            }
        }
        return minPrice;
    }

    int buyDirectly(vector<int>& price, vector<int>& needs) {
        int total = 0;
    	for (int i = 0; i < needs.size(); i++) {
    		total += price[i] * needs[i];
    	}
    	return total;
    }
};
