#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Info {
    Info(int hostId, int listId, string score, string city): 
        hostId_(hostId), 
        listId_(listId), 
        score_(score), 
        city_(city) {
    }
    int hostId_;
    int listId_;
    string score_;
    string city_;
    
    string print() const {
        return to_string(hostId_) + "," + to_string(listId_) + "," + score_ + "," + city_;
    }
};

struct InfoQue {
    InfoQue() {
        data = {};
        nextIndex = 0;
    }

    vector<Info> data;
    int nextIndex;
};

struct InfoCmp {
    bool operator()(Info& a, Info& b) {
        return stof(a.score_) < stof(b.score_);
    }
};

struct InfoQueCmp {
    bool operator()(InfoQue* q1, InfoQue* q2) {
        Info a = q1->data[q1->nextIndex]; 
        Info b = q2->data[q2->nextIndex];
        return stof(a.score_) < stof(b.score_);
    }
};

class Solution {
public:
    // Complete the paginate function below.
    vector<string> paginate(int resultsPerPage, vector<string>& results) {
        if (results.empty()) {
            return {};
        }
        parititionByHostId(results);

        int pages = 0, pageCount = results.size() / resultsPerPage + 1;
        vector<string> ans;
        while (pages < pageCount) {
            priority_queue<Info, vector<Info>, InfoCmp> eachHost;
            for (auto &kv : dict) {
                InfoQue* que = kv.second;
                if (que->nextIndex < que->data.size()) {
                    eachHost.push(que->data[que->nextIndex++]);
                }
            }
            if (eachHost.empty()) {
                break;
            }
            ans.emplace_back("");

            if (eachHost.size() >= resultsPerPage) {
                for (int i = 0; i < resultsPerPage; i++) {
                    ans.emplace_back(eachHost.top().print());
                    eachHost.pop();
                }
                // if more than a page, remaining unsed, need to decrease nextIndex
                while (!eachHost.empty()) {
                    Info info = eachHost.top();
                    eachHost.pop();
                    dict[info.hostId_]->nextIndex--;
                }
            } else {
                int count = eachHost.size();
                while (!eachHost.empty()) {
                    ans.emplace_back(eachHost.top().print());
                    eachHost.pop();
                }
                
                priority_queue<InfoQue*, vector<InfoQue*>, InfoQueCmp> pq1;
                for (auto &kv : dict) {
                    InfoQue* que = kv.second;
                    if (que->nextIndex < que->data.size()) {
                        pq1.push(que);
                    }
                }

                if (pq1.empty()) {
                    break;
                }

                while (count < resultsPerPage) {
                    if (pq1.empty()) {
                        break;
                    }

                    InfoQue* que = pq1.top();
                    ans.emplace_back(que->data[que->nextIndex++].print());
                    if (que->nextIndex == que->data.size()) {
                        pq1.pop();
                    }
                    count++;
                }
            }
            pages++;
        }
        return ans;
    }

private:
    void parititionByHostId(const vector<string> &results) {
        for (auto& line : results) {
            int start = 0, end = line.find(',');
            int hostId = stoi(line.substr(start, end - start));

            start = end + 1;
            end = line.find(',', start);
            int listId = stoi(line.substr(start, end - start));

            start = end + 1;
            end = line.find(',', start);
            string score = line.substr(start, end - start);

            start = end + 1;
            string city = line.substr(start);

            if (!dict.count(hostId)) {
                dict[hostId] = new InfoQue();
            }
            dict[hostId]->data.emplace_back(hostId, listId, score, city);
        }
    }

    unordered_map<int, InfoQue*> dict;
    unordered_map<int, int> nextIndex;
};

int main() {
    Solution s;
    vector<string> results = {
        "1,28,300.6,San Francisco", 
        "4,5,209.1,San Francisco", 
        "20,7,203.4,Oakland", 
        "6,8,202.9,San Francisco", 
        "6,10,199.8,San Francisco", 
        "1,16,190.5,San Francisco", 
        "6,29,185.3,San Francisco", 
        "7,20,180.0,Oakland", 
        "6,21,162.2,San Francisco", 
        "2,18,161.7,San Jose", 
        "2,30,149.8,San Jose", 
        "3,76,146.7,San Francisco", 
        "2,14,141.8,San Jose"
    };
    vector<string> ans = s.paginate(5, results);

    cout << "----------------------------------" << endl;
    for (auto & line : ans) {
        cout << line << endl;
    }
    return 0;
}
