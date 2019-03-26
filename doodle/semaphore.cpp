#include <unistd.h>
#include <thread>
#include <vector>
#include <iostream>
#include "semaphore.h"
using namespace std;

int main() {
    Semaphore sem(5);

    auto wtf = [&] {
        sem.wait();
        cout << this_thread::get_id() << " do sth for a long time" << '\n';
        sleep(10);
        sem.post();
    };

    vector<thread> threads;
    for (int i = 0; i < 13; i++) {
        threads.emplace_back(wtf);
        sleep(1);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
