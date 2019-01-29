class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m_[key].emplace(timestamp, std::move(value));    
    }
    
    string get(string key, int timestamp) {
        auto kit = m_.find(key);
        if (kit == m_.end()) {
            return "";
        }
        auto it = kit->second.upper_bound(timestamp);
        if (it == kit->second.begin()) {
            return "";
        }
        return prev(it)->second;
    }
private:
    // <key, <ts, value>>
    unordered_map<string, map<int, string>> m_;
    /*
     * 默认Compare为less<Key>, 即为增序
     * template < 
     *     class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
       > class map;
     */
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
