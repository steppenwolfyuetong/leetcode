#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
public:
    explicit Semaphore(int n): count_(n) {
    }

    void wait() {
        unique_lock<mutex> lock(m_);
        available_.wait(lock, [this] {return count_ > 0;});
        --count_;
    }

    void post() {
        lock_guard<mutex> lock(m_);
        ++count_;
        available_.notify_all();
    }

    int count() {
        lock_guard<mutex> lock(m_);
        return count_;
    }

private:
    mutex m_;
    condition_variable available_;
    int count_;
};
