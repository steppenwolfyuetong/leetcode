#include "../leetcode.h"
// https://leetcode.com/articles/minimum-cost-to-hire-k-workers/

/*
1. for any two workers in the paid group, we have 
        wage[i] : wage[j] = quality[i] : quality[j]
        wage[i] : quality[i] = wage[j] : quality[j]
   We pay wage to every worker in the group with the same ratio compared to his own quality.

2. So to minimize the total wage, we want a small ratio.  So we sort all workers with their expected ratio, and pick up K first worker.
   Now we have a minimum possible ratio for K worker and we their total quality.
*/

struct Worker {
    Worker(int quality, int wage): quality_(quality), wage_(wage) {
        ratio_ = (double)wage / (double)quality;
    }

    bool operator<(const Worker &other) const {
        return ratio_ < other.ratio_;
    }

    friend ostream& operator<<(ostream& os, const Worker& worker) {
        os << worker.quality_ << " " << worker.wage_ << " " << worker.ratio_;
        return os;
    }

    int quality_;
    int wage_;
    double ratio_;          // wage for per quality, with lower ratio, the amount of money is less.
};
/*
1. sort the array by the wage[i] / quality[i] (named as ratio[i]) in ascending order.

2. If I choose the i-th worker and it is make sense to use ratio[i] * quality[j] to pay worker j, where j <= i, 
   because ratio[j] <= ratio[i], so j-th worker can get more wage with ratio[i]
   
   wage[j] = ratio[j] * quality[j] <= ratio[i] * quality[j] .

3. when I choose the ratio[i] to pay workers, what I need to do is to find the K smallest quality among [0,i], 
   priority queue of size K can be used for maintain the K smallest quality.
*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<Worker> workers;
        for (int i = 0; i< quality.size(); i++) {
            workers.emplace_back(quality[i], wage[i]);
        }
        sort(workers.begin(), workers.end());           // sort workers by its ratio

        priority_queue<int> pq;                         // max heap of quality, so we can get group of minimum quality of size K
        int total_quality = 0;                          // we can get money of paid group = ratio[i] * total_quality
        double rt = DBL_MAX;
        for (const auto& worker : workers) {
            total_quality += worker.quality_;
            pq.push(worker.quality_);
            if (pq.size() > K) {
                total_quality -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                rt = min(rt, total_quality * worker.ratio_);
            }
        }

        return rt;
    }
};

int main() {
    Solution s;
    vector<int> quality = {10, 20 ,5};
    vector<int> wage = {70, 50, 30};
    cout << s.mincostToHireWorkers(quality, wage, 2) << endl;
    return 0;
}
