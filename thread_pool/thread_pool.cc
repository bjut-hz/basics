#include "thread_pool.h"
#include <iostream>
#include <chrono>
#include <assert.h>

int Add(int a, int b, int& sum) {
	sum = a + b;
	return a + b;
}

void SayHello() {
	std::cout << "hello world" << std::endl;
}
// 最好用io密集的任务来测试
int main() {
	//std::cout << "add number with one single thread ..." << std::endl;
	//auto t1 = std::chrono::system_clock::now();

	//auto t2 = std::chrono::system_clock::now();
	//std::cout << (t2 - t1).count() << " tick count..  " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds" << std::endl;


	//std::cout << "add number with thread pool ..." << std::endl;
	//auto t3 = std::chrono::system_clock::now();

	//auto t4 = std::chrono::system_clock::now();
	//std::cout << (t4 - t3).count() << " tick count..  " << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << " microseconds" << std::endl;

	// with return value test
	ThreadPool pool(2);
	int sum = 0;
	auto future = pool.Sumbit(Add, 1, 2, std::ref(sum));
	assert(future.get() == sum);
}
