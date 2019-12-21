#include "object_pool.h"
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <atomic>

class TimeElapse {
public:
    explicit TimeElapse(std::string name) {
        std::cout << "=========== " << name << " begin ===========" << std::endl;
        start_ = std::chrono::system_clock::now();
        name_ = name;
    }

    ~TimeElapse() {
        auto end = std::chrono::system_clock::now();

        std::cout << name_ << "  Summary: " << (end - start_).count() << " tick count. "
            << std::chrono::duration_cast<std::chrono::seconds>(end - start_).count() << " seconds" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::system_clock>			start_;
    std::string													name_;
};


struct Apple {
    int price = 0;
    int discount = 9;
};


#define OBJECT_NUM 10000000

void TestNewDelete() {
    TimeElapse e = TimeElapse("TestNewDelete");

    for (int i = 0; i < OBJECT_NUM; ++i) {
        Apple* tmp = new Apple();
        delete tmp;
    }
}

void TestObjectPool() {
    TimeElapse e = TimeElapse("TestObjectPool");
    ObjectPool<Apple, 1> pool;
    for (int i = 0; i < OBJECT_NUM; ++i) {
        Apple* tmp = pool.Get();
        pool.Free(tmp);
    }
}
int main() {
    TestNewDelete();
    TestObjectPool();
}