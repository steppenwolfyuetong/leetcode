#include <map>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        dict[val].push_back(vec.size());
        vec.push_back(make_pair(val, dict[val].size() - 1));
        return dict[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(dict[val].empty())
            return false;

        int index = dict[val].back();
        /* copy the last element, end modify its index*/
        vec[index] = vec.back();
        dict[vec[index].first][vec[index].second] = index;
        dict[val].pop_back();
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand() % vec.size()].first;
    }
private:
    // pair.first: the actual value stored; 
    // pair.second: the index of the pointer in the idx_map[pair.first]; 
    // so dict[pair.first][pair.second] is the index of the value in the vec.
    // That is dict[vec[i].first][vec[i].second] == i
    vector<pair<int,int> > vec;
    map<int,vector<int> > dict;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    RandomizedCollection *rCollect = new RandomizedCollection();
    cout << rCollect->insert(1) << endl;
    cout << rCollect->insert(1) << endl;
    cout << rCollect->insert(2) << endl;
    cout << rCollect->insert(2) << endl;
    cout << rCollect->insert(3) << endl;
    cout << rCollect->insert(3) << endl;
    rCollect->display();
    cout << rCollect->remove(1) << endl;
    rCollect->display();
    cout << rCollect->remove(1) << endl;
    rCollect->display();
    cout << rCollect->remove(3) << endl;
    rCollect->display();
    cout << rCollect->remove(3) << endl;
    rCollect->display();
    cout << rCollect->getRandom() << endl;
    cout << rCollect->getRandom() << endl;
    cout << rCollect->getRandom() << endl;
    cout << rCollect->getRandom() << endl;
    cout << rCollect->getRandom() << endl;
    cout << rCollect->getRandom() << endl;
    cout << rCollect->getRandom() << endl;
    return 0;
}
