#include "singleton.h"

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
} // namespace DP

