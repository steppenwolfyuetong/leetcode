class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data_ = vector<int>(k);        
        front_ = rear_ = 0;
        count_ = 0;
        size_ = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data_[rear_++] = value;    
        if (rear_ == size_) {
            rear_ = 0;
        }
        count_++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front_++;
        if (front_ == size_) {
            front_ = 0;
        }
        count_--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data_[front_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (rear_ == 0) {
            return data_[size_ - 1];
        } else {
            return data_[rear_ -1];
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count_ == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count_ == size_;
    }
private:
    vector<int> data_;
    int front_;                     // front_ points to the first element
    int rear_;                      // rear_ points to the next element of last element
    int count_;                     // count_ is elements in queue
    int size_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
