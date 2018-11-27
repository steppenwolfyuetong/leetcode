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

class WordDictionary 
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) 
    {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        return dfs(word, root);
    }

    bool dfs(string word,TrieNode *cur)
    {
        if(!cur)
            return false;
        for(int i = 0; i < word.length(); i++)
        {
            if(word[i] != '.')
            {
                return dfs(word.substr(i+1),cur->getChild(word[i]));
            }
            else
            {
                for(vector<TrieNode*>::iterator iter = cur->children.begin(); iter != cur->children.end(); iter++)
                {
                    if(dfs(word.substr(i+1),*iter))
                        return true;
                }
                return false;
            }
        }
        return cur->isEnd;
    }
private:
	TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
    WordDictionary trie;
    trie.addWord("a");
    cout << trie.search(".") << endl;
    return 0;
}
