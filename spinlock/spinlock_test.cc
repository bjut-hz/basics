#include "spinlock.h"
#include <thread>
#include <iostream>
#include <mutex>

SpinLock lock;
int counter = 0;
void Add() {
	for (int i = 0; i < 10000000; ++i) {
		std::lock_guard<SpinLock> l(lock);
		counter += 1;
	}
}
int main() {
	std::thread t1(Add);
	std::thread t2(Add);
	std::thread t3(Add);

	t1.join();
	t2.join();
	t3.join();
	std::cout << counter << std::endl;
}