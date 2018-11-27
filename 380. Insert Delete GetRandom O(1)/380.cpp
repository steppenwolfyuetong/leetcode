class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.find(val) != dict.end())
            return false;
        vec.push_back(val);
        dict.insert(pair<int,int>(val,vec.size() - 1));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.find(val) == dict.end())
            return false;
        int last = vec.back();
        vec[dict[val]] = last;
        dict[last] = dict[val];

        dict.erase(val);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }

    void display()
    {
        cout << "vec:";
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << ' ';
        cout << endl;

        cout << "dict:";
        for(map<int,int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
            cout << iter->first << '/' << iter->second << ' ';
        cout << endl;
    }
private:
    vector<int> vec;
    map<int,int> dict;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
