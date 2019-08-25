#ifndef SINGLETON_H_
#define SINGLETON_H_

#include "basic.h"

namespace DP {
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

} // namespace DP

#endif // SINGLETON_H_