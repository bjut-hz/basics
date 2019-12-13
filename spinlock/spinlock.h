#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <atomic>

class SpinLock {
public:
    SpinLock() {
        lock_.clear();
    }

    SpinLock(SpinLock&) = delete;
    ~SpinLock() = default;

    bool try_lock() {
        return !lock_.test_and_set(std::memory_order_acquire);
    }

    void lock() {
        while(lock_.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        lock_.clear(std::memory_order_release);
    }
private:
    std::atomic_flag lock_;
};

#endif // SPINLOCK_H