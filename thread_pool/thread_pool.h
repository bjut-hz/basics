#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <mutex>
#include <condition_variable>
#include <memory>
#include <vector>
#include <thread>
#include <functional>
#include <queue>
#include <future>

class ThreadPool {
public:
	explicit ThreadPool(int size) {
		data_ = std::make_shared<data>();

		for(int i = 0; i < size; ++i) {
			std::thread(
				// 这里不能用引用,因为需要保证线程池被析构后,data对象依然不被析构
				[data = data_](){
					std::unique_lock<std::mutex> lock(data->mu_);
					for(;;) {
						if(!data->tasks_.empty()) {
							auto task = std::move(data->tasks_.front());
							data->tasks_.pop();

							// 空出锁供使用
							lock.unlock();
							task();
							lock.lock();
						} else if(data->shut_down) {
							break;
						} else {
							data->cv.wait(lock);
						}
					}
				}
			).detach();
		}
	}

	~ThreadPool() {
		if(data_) {
			{
				std::lock_guard<std::mutex> lock(data_->mu_);
				data_->shut_down = true;
			}
		}

		data_->cv.notify_all();
	}

	// void(void) template specialization
	template <typename Func>
	void Sumbit(Func&& task) {
		{
			std::lock_guard<std::mutex> lock(data_->mu_);
			data_->tasks_.emplace(std::forward<Func>(task));
		}
		data_->cv.notify_one();
	}

	template <typename R, typename... Args>
	auto Sumbit(R&& f, Args&& ...args) -> std::future<decltype(f(args...))> {
		auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>( 
			std::bind(std::forward<R>(f), std::forward<Args>(args)...)
		);
		{
			std::lock_guard<std::mutex> lock(data_->mu_);
			// 包装成void(void)类型
			data_->tasks_.emplace([task_ptr](){
				(*task_ptr)();
			});
		}
		data_->cv.notify_one();
		return task_ptr->get_future();
	}

private:
	struct data {
		std::condition_variable 				cv;
		std::mutex								mu_;
		std::queue<std::function<void(void)>> 		tasks_;
		bool									shut_down = false;
	};

	std::shared_ptr<data> data_;
};

#endif // THREAD_POOL_H