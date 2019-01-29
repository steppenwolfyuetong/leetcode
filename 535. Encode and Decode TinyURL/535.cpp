#include <string>
#include <unordered_map>
#include <atomic>
#include <iostream>
using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short_.find(longUrl) != long2short_.end()) {
            return long2short_[longUrl];
        }
        string res;
        int id = id_.fetch_add(1), temp = id;
        while (id) {
            res += dict_[id % 62];
            id /= 62;
        }
        reverse(res.begin(), res.end());

        long2short_[longUrl] = res;
        id2long_[temp] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = 0;
        for (int i = 0; i < shortUrl.size(); i++) {
            id = 62 * id + (int)(dict_.find(shortUrl[i]));
        }
        if (id2long_.find(id) != id2long_.end()) {
            return id2long_[id];
        }
        return "";
    }
private:
    string dict_ = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    atomic<int> id_ = {0};
    int shorUrlLength_ = 6;
    unordered_map<string, string> long2short_;
    unordered_map<int, string> id2long_;
};

int main() {
    Solution s;
    string a = s.encode("www.youtube.com");
    string b = s.decode(a);
    
    cout << a << " " << b << endl;
    return 0;
}

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
