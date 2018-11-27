#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class Node {
public:
    Node(int k, int v, int f): key(k), value(v), freq(f) {}
    int key;
    int value;
    int freq;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(km.find(key) == km.end())
            return -1;

        Node node = *km[key]; 
        fm[node.freq].erase(km[key]);
        node.freq++;
        fm[node.freq].emplace_front(node);
        km[key] = fm[node.freq].begin();
        if(fm[minFreq].size() == 0)
            minFreq++;
        return node.value;
    }
    
    void put(int key, int value) {
        if(get(key) != -1)
        {
            km[key]->value = value;
            return;
        }
        
        if(km.size() == capacity)
        {
            km.erase(fm[minFreq].back().key);
            fm[minFreq].pop_back();
        }

        fm[1].emplace_front(Node(key, value, 1));
        km[key] = fm[1].begin();
        minFreq = 1;
    }

    void display()
    {
        cout << "KeyMap:" << endl;
        for(auto kv : km)
            cout << kv.second->key << ' ' << kv.second->value << ' ' << kv.second->freq << endl;

        cout << "FreqMap:" << endl;
        for(auto kv : fm)
        {
            cout << kv.first << ": ";
            for(auto node : kv.second)
                cout << node.key << ' ';
            cout << endl;
        }
        cout << endl;
    }
private:
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>::iterator> km;
    unordered_map<int, list<Node>> fm;
};


int main()
{
    LFUCache *cache = new LFUCache(2);
    
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
