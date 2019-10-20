#ifndef CHAN_H_
#define CHAN_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <assert.h>
#include <iostream>

template<typename T, unsigned int N = 0>
class chan {
public:
	chan() : closed_(false), r_waiting_(0), w_waiting_(0) {}
	~chan() {
		std::cout << "size: " << queue_.size();
	}
	int Send(T data) {
		std::unique_lock<std::mutex> lock(mu_);
		while(queue_.size() == N) {
			++w_waiting_;
			w_cv_.wait(lock);
			--w_waiting_;
		}

		assert(queue_.size() < N);
		queue_.push(data);
		
		if(r_waiting_ > 0) {
			r_cv_.notify_one();
		}
		return 0;
	}

	T Recv() {
		std::unique_lock<std::mutex> lock(mu_);
		while(queue_.size() == 0) {
			if (closed_) return T();

			++r_waiting_;
			r_cv_.wait(lock);
			--r_waiting_;
		}
	
		auto data = queue_.front();
		queue_.pop();

		if(w_waiting_ > 0) {
			w_cv_.notify_one();
		}
		return data;
	}
	int Close() {
		int success = 0;
		std::lock_guard<std::mutex> lock(mu_);
		if(closed_) {
			success = -1;
		} else {
			closed_ = true;
			r_cv_.notify_all();
			w_cv_.notify_all();
		}
		return success;
	}
	bool closed() { return closed_; }
	int size() { return queue_.size(); }

private:
	std::queue<T> queue_;
	// shared properties
	std::mutex mu_;
	std::condition_variable r_cv_;
	std::condition_variable w_cv_;
	bool closed_;
	int r_waiting_;
	int w_waiting_;
};


// unbufferd channel
template<typename T>
class chan<T, 0> {
public:
	int Send();
	int Recv();
	int Close();
	bool closed();
	int size();

private:
	T data_;
	std::mutex r_mu_; // 
	std::mutex w_mu_; // 写锁保证了在多个线程进行写操作的,只有一个线程的数据是保存成功的并且等到被读取,其它线程需要等待此锁

	std::mutex mu_;
	std::condition_variable r_cv_;
	std::condition_variable w_cv_;
	bool closed_;
	int r_waiting_;
	int w_waiting_;
};

#endif // CHAN_H_