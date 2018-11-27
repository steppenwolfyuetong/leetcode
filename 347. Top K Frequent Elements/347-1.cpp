//quick select
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> rt;
        if(nums.empty())
            return rt;

        unordered_map<int, int> cnt;
        for(auto num : nums)
        {
            cnt[num]++;
        }
        vector<pair<int, int> > num_count;
        for(auto kv : cnt)
        {
            num_count.push_back(kv);
        }

        select(num_count, k);
        
        //result is top k elements
        for(int i = 0; i < k && i < num_count.size(); i++)
        {
            rt.push_back(num_count[i].first);
        }
        return rt;
    }

    //quick select
    void select(vector<pair<int, int> > &data, int k)
    {
        int low = 0, high = data.size() - 1;
        while(low < high)
        {
            //int index = partition1(data, low, high);
            int index = partition2(data, low, high);
            if(index < k)
                low = index + 1;
            else if(index > k)
                high = index - 1;
            else
                break;
        }
        return;
    }

    //从大到小排序 双向扫描
    int partition1(vector<pair<int, int> > &data, int low, int high)
    {
        pair<int, int> pivot = data[low];
        while(low < high)
        {
            while(low < high && data[high].second <= pivot.second)
                high -= 1;
            data[low] = data[high];
            while(low < high && data[low].second >= pivot.second)
                low += 1;
            data[high] = data[low];
        }
        data[low] = pivot;
        return low;
    }
    
    //从大到小排序 单向扫描
    int partition2(vector<pair<int, int> > &data, int low, int high)
    {
        pair<int, int> pivot = data[high];
        int index = low;
        for(int i = low; i < high; i++)
        {
            if(data[i].second > pivot.second)
            {
                swap(data[i],data[index]);
                index += 1;
            }
        }
        swap(data[index],data[high]);
        return index;
    }
};
