/*
    Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */

/*
The good thing about lists is that iterators are never invalidated by modifiers (unless erasing the element itself). This way, we can store the iterator to the corresponding LRU queue in the values of the hash map. Since using erase on a list with an iterator takes constant time, all operations of the LRU cache run in constant time.
*/

class LRUCache{
    //m_list为LRU队列 越靠前越是最近使用
    size_t m_capacity;
    list<pair<int, int>> m_list;                               // m_list_iter->first: key, m_list_iter->second: value;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; // m_map_iter->first: key, m_map_iter->second: list iterator;
public:
    LRUCache(size_t capacity):m_capacity(capacity) {
    }

    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end())
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }

    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end())
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity)
        {
           int key_to_del = m_list.back().first; 
           m_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
