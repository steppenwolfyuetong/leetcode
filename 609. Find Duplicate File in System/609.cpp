#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> result;

        for (auto& path : paths) {
            stringstream ss(path);
            string dir, file;
            ss >> dir;
            while (ss >> file) {
                int index = file.find('(');
                string filename = dir + '/' + file.substr(0, index);
                string content = file.substr(index + 1, file.find(')') - index - 1);
                dict[content].push_back(filename);
            }
        }

        for (auto& p : dict) {
            if (p.second.size() > 1) {
                result.emplace_back(p.second);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    s.findDuplicate(paths);
    return 0;
}

/*
1. Imagine you are given a real file system, how will you search files? DFS or BFS ?
In general, BFS will use more memory then DFS. However BFS can take advantage of the locality of files in inside directories, and therefore will probably be faster

2. If the file content is very large (GB level), how will you modify your solution?
In a real life solution we will not hash the entire file content, since it's not practical. Instead we will first map all the files according to size. Files with different sizes are guaranteed to be different. We will than hash a small part of the files with equal sizes (using MD5 for example). Only if the md5 is the same, we will compare the files byte by byte

3. If you can only read the file by 1kb each time, how will you modify your solution?
This won't change the solution. We can create the hash from the 1kb chunks, and then read the entire file if a full byte by byte comparison is required.

What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?
Time complexity is O(n^2 * k) since in worse case we might need to compare every file to all others. k is the file size

How to make sure the duplicated files you find are not false positive?
We will use several filters to compare: File size, Hash and byte by byte comparisons.
*/
