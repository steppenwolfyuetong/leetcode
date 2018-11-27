#include <set>
#include <vector>
#include <string>
#include <iosteram>
using namespase std;

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
    Trie(const vector<string>& words) {
        root = new TrieNode();
        for(string word : words)
        {
            insert(word);
        }
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
public:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> rt;
        if(board.empty() || board.front().empty())
            return rt;

        vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size(), false));
        Trie* trie = new Trie(words);
        string cur = "";
        set<string> result;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.front().size(); j++)
            {
                dfs(board, i, j, trie->root, cur, result, visited);
            }
        }

        for(auto word : result)
        {
            rt.push_back(word);
        }
        return rt;
    }

    void dfs(const vector<vector<char>> &board, int x, int y, TrieNode* trie, string &cur, set<string> &result, vector<vector<bool>> &visited)
    {
        if(x < 0 || y < 0 || x >= board.size() || y >= board.front().size())
            return;
        if(visited[x][y] == true)
            return;

        trie = trie->getChild(board[x][y]);
        if(trie)
        {
            visited[x][y] = true;
            cur += board[x][y];
            if(trie->isEnd)
                result.insert(cur);

            dfs(board, x + 1, y, trie, cur, result, visited);
            dfs(board, x - 1, y, trie, cur, result, visited);
            dfs(board, x, y + 1, trie, cur, result, visited);
            dfs(board, x, y - 1, trie, cur, result, visited);
            cur.pop_back();
            visited[x][y] = false;
            
        }
    }
};
