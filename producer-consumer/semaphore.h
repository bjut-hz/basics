#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include <mutex>
#include <condition_variable>

class Semaphore {
public:
	Semaphore(int count = 0) : count_(count) {}

	inline void V() {
		std::unique_lock<std::mutex> lock(mu_);
		count_++;
		cv_.notify_one();
	}

	inline void P() {
		std::unique_lock<std::mutex> lock(mu_);
		while(0 == count_) {
			cv_.wait(lock);
		}
		count_--;
	}
	

private:
	int count_;
	std::mutex mu_;
	std::condition_variable cv_;
};

#endif // SEMAPHORE_H_