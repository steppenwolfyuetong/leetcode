#include <vector>
#include <iostream>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): value(' ') , isEnd(false) {}
    TrieNode(char ch): value(ch), isEnd(false) {}
    char value;
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode* getChild(char ch)
    {
        for(vector<TrieNode*>::iterator iter = children.begin(); iter != children.end(); iter++)
            if((*iter)->value == ch)
                return *iter;
        return NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++)
        {
            TrieNode *child = cur->getChild(word[i]);
            if(!child)
            {
                child = new TrieNode(word[i]);
                cur->children.push_back(child);
				cur = child;
            }
            else
            {
                cur = child;
            }
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++)
        {
            TrieNode *child = cur->getChild(word[i]);
            if(!child)
                return false;
            else
                cur = child;
        }
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i = 0; i < prefix.length(); i++)
        {
            TrieNode *child = cur->getChild(prefix[i]);
            if(!child)
                return false;
            else
                cur = child;
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie trie;
    trie.insert("happy");
    trie.insert("birthday");
    cout << trie.search("happy") << endl;;
    cout << trie.search("birth") << endl;
    cout << trie.startsWith("birth") << endl;
	system("pause");
    return 0;
}

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
