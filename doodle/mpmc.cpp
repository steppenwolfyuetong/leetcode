#include <map>
#include <unistd.h>
#include <thread>
#include <iostream>
#include "mpmc.h"

int main() {
    MPMCQueue<int> queue(50);
    auto produce = [&] {
        int i = 0;
        for (i = 0; i < 100; i++) {
            queue.put(i);
        }
    };

    std::map<int, int> count;
    std::map<std::thread::id, int> threadCount;
    std::mutex m;
    
    auto consume = [&] {
        std::thread::id id = std::this_thread::get_id();
        while (true) {
            int x = queue.take();
            {
                std::lock_guard<std::mutex> lock(m);
                count[x]++;
                threadCount[id]++;
            }
        }
    };

    std::vector<std::thread> producers;
    for (int i = 0; i < 5; i++) {
        producers.emplace_back(std::thread(produce));
    }

    std::vector<std::thread> consumers;
    for (int i = 0; i < 5; i++) {
        consumers.emplace_back(std::thread(consume));
    }

    for (auto& consumer : consumers) {
        consumer.detach();
    }
    for (auto& producer : producers) {
        producer.join();
    }
    sleep(1);
    for (auto kv : count) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    for (auto kv : threadCount) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }

    return 0;
}
