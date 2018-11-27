/*
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/


#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int> > wordidx;
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i)
            wordidx[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> &idx1 = wordidx[word1];
        vector<int> &idx2 = wordidx[word2];
        int m = idx1.size(), n = idx2.size();
        int res = INT_MAX, i = 0, j = 0;
        while (i < m && j < n) {
            res = min(res, abs(idx1[i] - idx2[j]));
            if (idx1[i] > idx2[j]) 
                ++j;
            else 
                ++i;
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main()
{
    string a[] = {"practice", "makes", "perfect", "coding", "makes"};
    int size = 5;
    vector<string> words;
    for(int i = 0; i < size; i++)
    {
    	words.push_back(a[i]);
	}
	
	WordDistance s(words);
	cout << s.shortest("coding", "makes") << endl;
}
