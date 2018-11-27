#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
      Increasing frequencies
  ----------------------------->

+------+    +---+    +---+    +---+
| Head |----| 1 |----| 5 |----| 9 |  Frequencies
+------+    +-+-+    +-+-+    +-+-+
              |        |        |
            +-+-+    +-+-+    +-+-+     |
            |2,3|    |4,3|    |6,2|     |   Most recently used
            +-+-+    +-+-+    +-+-+     | 
                       |        |       |
                     +-+-+    +-+-+     |
 key,value pairs     |1,2|    |7,9|     |   Least recently used
                     +---+    +---+     v

*/

/*
 * keyMap保存<key, <value, freq>>
 * freqMap保存 某一频率 与 所有频率均为当前频率的key的链表 映射
 * iterMap保存 key 与 在freqMap[key]中的iterator(list<int>::iterator) 映射
 */

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyMap;          // <key, <value, freq>>
    unordered_map<int, list<int>> freqMap;              // <freq, list<key>>
    unordered_map<int, list<int>::iterator> iterMap;    // <key, list<key>::iterator>
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end())
        {
            return -1;
        }

        freqMap[keyMap[key].second].erase(iterMap[key]);            // 从当前频率的链表中删除
        keyMap[key].second++;                                       // 频率+1
        freqMap[keyMap[key].second].emplace_front(key);             // 添加到新的频率链表头部
        iterMap[key] = freqMap[keyMap[key].second].begin();         // 保存iterator
        if(freqMap[minFreq].size() == 0)                            // 检查minFreq是否为0 否则+1 由于key的频率刚+1 所以minFreq+1的链表一定不为空
            minFreq++;
        
        return keyMap[key].first;
    }
    
    void put(int key, int value) {
        if(capacity <= 0)
            return;

        if(get(key) != -1)                                          // 链表处理
        {
            keyMap[key].first = value;                              // 已有key 更新value
            return;
        }

        if(keyMap.size() >= capacity)                               // 从minFreq中链表中删除最后一个元素 即least recently used元素
        {
            keyMap.erase(freqMap[minFreq].back());
            iterMap.erase(freqMap[minFreq].back());
            freqMap[minFreq].pop_back();
        }

        keyMap[key] = make_pair(value, 1);                          // 添加新元素
        freqMap[1].emplace_front(key);
        iterMap[key] = freqMap[1].begin();
        minFreq = 1;
    }

    void display()
    {
        cout << "KeyMap:" << endl;
        for(auto kv : keyMap)
            cout << kv.first << ' ' << kv.second.first << ' ' << kv.second.second << endl;


        cout << "FreqMap:" << endl;
        for(auto kv : freqMap)
        {
            cout << kv.first << ": ";
            for(auto key : kv.second)
                cout << key << ' ';
            cout << endl;
        }
        cout << endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    LFUCache *cache = new LFUCache(2);
    
    /*
    cache->put(1,1);
    cache->display();
    cache->put(2,2);
    cache->display();
    cache->get(1);
    cache->display();
    cache->put(3,3);
    cache->display();
    cache->get(2);
    cache->display();
    cache->get(3);
    cache->display();
    cache->put(4,4);
    cache->display();
    cache->get(1);
    cache->display();
    cache->get(3);
    cache->display();
    cache->get(4);
    cache->display();
    */
    
    /*
    cache->get(2);
    cache->display();
    cache->put(2,6);
    cache->display();
    cache->get(1);
    cache->display();
    cache->put(1,5);
    cache->display();
    cache->put(1,2);
    cache->display();
    cache->get(1);
    cache->display();
    cache->get(2);
    cache->display();
    */
    return 0;
}
