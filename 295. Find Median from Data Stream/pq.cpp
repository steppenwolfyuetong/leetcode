class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        // 使两个堆平衡
        if(maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap;     //保存较大的一半数 最小堆
    priority_queue<int, vector<int>, less<int>> maxHeap;        //保存较小的一半数 最大堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
