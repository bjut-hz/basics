#ifndef SINGLETON_H_
#define SINGLETON_H_

#include<atomic>
#include<mutex>

#include "basic.h"

namespace DP {
	/*
	can only be used in single thread program
	*/
	class ThreadUnsafeSingleton{
	public:
		static ThreadUnsafeSingleton* GetInstance();
		static void Release();

		void SetNum(int);
		int GetNum();

	private:
		ThreadUnsafeSingleton() = default;

	private:
		static ThreadUnsafeSingleton* instance;
		int a_ = 0;
	};

	/* 
	thread safe implementation version 1:
	use mutex to guard instance
	*/
	class ThreadSafeSingletonVer1{
	public:
		static ThreadSafeSingletonVer1* GetInstance();
		static void Release();

	private:
		ThreadSafeSingletonVer1() = default;

	private:
		static ThreadSafeSingletonVer1* instance;
		static std::mutex mu_;
	};


	/*
	double check to improve performance:
	bug prone cause re-order
	*/
	class ThreadSafeSingletonVer2{
	public:
		static ThreadSafeSingletonVer2* GetInstance();
		static void Release();

	private:
		ThreadSafeSingletonVer2() = default;

	private:
		static ThreadSafeSingletonVer2* instance;
		static std::mutex mu_;
	};

	/*
	use memory barrier
	*/

	class ThreadSafeSingletonVer3{
	public:
		static ThreadSafeSingletonVer3* GetInstance();
		static void Release();

	private:
		ThreadSafeSingletonVer3() = default;

	private:
		static ThreadSafeSingletonVer3* instance;
		static std::mutex mu_;
	};

	/*
	use atomic
	*/
	class ThreadSafeSingletonVer4{
	public:
		static ThreadSafeSingletonVer4* GetInstance();
		static void Release();

	private:
		ThreadSafeSingletonVer4() = default;

	private:
		static std::atomic<ThreadSafeSingletonVer4*> instance;
		static std::mutex mu_;
	};

	/*
	final vsersion: use static variable
	*/
	class ThreadSafeSingletonVer5{
	public:
		static ThreadSafeSingletonVer5* GetInstance();
		static void Release();

	private:
		ThreadSafeSingletonVer5() = default;
	};

} // namespace DP

#endif // SINGLETON_H_