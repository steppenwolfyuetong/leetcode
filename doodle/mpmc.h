#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

template<typename T>
class MPMCQueue {
public:
    explicit MPMCQueue(int n): capacity_(n) {
    }

    void put(T&& x) {
        std::unique_lock<std::mutex> lock(mutex_);
        notFull_.wait(lock, [this] {return queue_.size() < capacity_;});
        queue_.push(std::move(x));
        notEmpty_.notify_all();
    }

    void put(const T& x) {
        std::unique_lock<std::mutex> lock(mutex_);
        notFull_.wait(lock, [this] {return queue_.size() < capacity_;});
        queue_.push(x);
        notEmpty_.notify_all();
    }

    T take() {
        std::unique_lock<std::mutex> lock(mutex_);
        notEmpty_.wait(lock, [this] {return !queue_.empty();});
        T x(std::move(queue_.front()));
        queue_.pop();
        notFull_.notify_all();
        return x;
    }

    size_t size() {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }
private:
    std::mutex mutex_;
    std::condition_variable notEmpty_;
    std::condition_variable notFull_;
    std::queue<T> queue_;
    int capacity_;
};
