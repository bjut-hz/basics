#include "singleton.h"
#include "barrier.h"

namespace DP{
	// !!!!It is not possible to write the implementation of a template class in a separate cpp file and compile. 
	// so you can not put the Singleton with template implementation here.
	ThreadUnsafeSingleton* ThreadUnsafeSingleton::instance = nullptr;

	ThreadUnsafeSingleton* ThreadUnsafeSingleton::GetInstance(){
		if (nullptr == instance) {
			instance = new ThreadUnsafeSingleton();
		}
		return instance;
	}

	void ThreadUnsafeSingleton::Release(){
		if (nullptr != instance) {
			delete instance;
			instance = nullptr;
		}
	}

	int ThreadUnsafeSingleton::GetNum() {
		return a_;
	}

	void ThreadUnsafeSingleton::SetNum(int a) {
		a_ = a;
	}

	// ThradSafeSingletonVer1 implementation
	// cons: lock granularity is too large, every call will use lock
	ThreadSafeSingletonVer1* ThreadSafeSingletonVer1::instance = nullptr;
	std::mutex ThreadSafeSingletonVer1::mu_;
	ThreadSafeSingletonVer1* ThreadSafeSingletonVer1::GetInstance(){
		std::lock_guard<std::mutex> lock(mu_);
		if (nullptr == instance) {
			instance = new ThreadSafeSingletonVer1();
		}
		return instance;
	}

	void ThreadSafeSingletonVer1::Release(){
		std::lock_guard<std::mutex> lock(mu_);
		if (nullptr != instance) {
			delete instance;
			instance = nullptr;
		}
	}

	// ThreadSafeSingletonVer2 implentation
	// use double check with minimum granularity lock
	// 这种实现会出现bug,原因在于instance变量的读写不是原子操作,instance可能分成了多个步骤,由于reorder导致把instance置为非nullptr的操作重排了前面
	// 多个线程的时候,其中一个还未完整的构造完instance实例,但是另一个线程判断instance不为nullptr并返回之
	// 需要正确的同步多个线程的情况下读写instance时的可见性
	ThreadSafeSingletonVer2* ThreadSafeSingletonVer2::instance = nullptr;
	std::mutex ThreadSafeSingletonVer2::mu_;
	ThreadSafeSingletonVer2* ThreadSafeSingletonVer2::GetInstance(){
		if(nullptr == instance) {
			std::lock_guard<std::mutex> lock(mu_);
			if(nullptr == instance) {
				instance = new ThreadSafeSingletonVer2();
			}
		}
		return instance;
	}

	// ThreadSafeSingletonVer3 implentation
	// 使用内存屏障做同步,可以参考leveldb的AtomicPointer中内存屏障的使用
	// 锁的使用保证了只有一个线程写,使用内存屏障保证在为instance赋值时,该对象一定初始化完了
	// 该内存屏障实现对cpu重排未做任何防护,在并发写的时候需要用锁保证正确性
	// 内存重排序分为编译器重排以及cpu重排
	// 有两个共享变量temp以及intance,使用内存屏障保证了顺序,用来做线程之间的同步操作
	// 如果多线程之间只有一个共享变量,保证该变量的原子性就不会出现并发问题
	ThreadSafeSingletonVer3* ThreadSafeSingletonVer3::instance = nullptr;
	std::mutex ThreadSafeSingletonVer3::mu_;
	ThreadSafeSingletonVer3* ThreadSafeSingletonVer3::GetInstance(){
		ThreadSafeSingletonVer3* temp = instance; 
		MemoryBarrier(); // 禁止向下reorder,可以保证拿到的instance值是最新的
		if(nullptr == temp) { 
			std::lock_guard<std::mutex> lock(mu_); // make sure only one thread can enter in
			temp = instance;
			if(nullptr == temp) {
				temp = new ThreadSafeSingletonVer3();
				MemoryBarrier(); // 禁止向上reorder,保证instance赋值时,对象已经构造完整
				instance = temp;
			}
		}
		return instance;
	}

	// ThreadSafeSingletonVer4 implentation
	std::atomic<ThreadSafeSingletonVer4*> ThreadSafeSingletonVer4::instance = nullptr;
	std::mutex ThreadSafeSingletonVer4::mu_;
	ThreadSafeSingletonVer4* ThreadSafeSingletonVer4::GetInstance(){
		if(nullptr == instance.load()) { 
			std::lock_guard<std::mutex> lock(mu_); // make sure only one thread can enter in
			if(nullptr == instance.load()) {
				instance.store(new ThreadSafeSingletonVer4());
			}
		}
		return instance;
	}

	// static variable
	ThreadSafeSingletonVer5* ThreadSafeSingletonVer5::GetInstance(){
		static ThreadSafeSingletonVer5 instance;
		return &instance;
	}
} // namespace DP

