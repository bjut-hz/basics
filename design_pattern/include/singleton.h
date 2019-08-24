#ifndef SINGLETON_H_
#define SINGLETON_H_

namespace DP {

	template<typename T>
	class ThreadUnsafeSingleton{
	public:
		ThreadUnsafeSingleton() = delete;
		static T* GetInstance() {
			if (nullptr == instance) {
				instance = new T();
			}
			return instance;
		};

		static void Release() {
			if (nullptr != instance) {
				delete instance;
				instance = nullptr;
			}
		}

	private:
		static T* instance;
	};

	template<class T>
	T* ThreadUnsafeSingleton<T>::instance = nullptr;
} // namespace DP

#endif // SINGLETON_H_