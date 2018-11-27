/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

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
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int rt = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                pos1 = i;
            }
            else if (words[i] == word2) {
                pos2 = i;
            }
            if (pos1 != -1 and pos2 != -1) {
                rt = min(rt, abs(pos1 - pos2));
            }
        }
        return rt;
    }
};

int main()
{
    string a[] = {"practice", "makes", "perfect", "coding", "makes"};
    int size = 5;
    vector<string> words;
    for(int i = 0; i < size; i++)
    {
    	words.push_back(a[i]);
	}
	
	Solution s;
	cout << s.shortestDistance(words, "coding", "makes") << endl;
}
