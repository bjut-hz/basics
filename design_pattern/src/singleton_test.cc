#include<thread>

#include "util/testharness.h"
#include "util/basic.h"
#include "singleton.h"


namespace DP {
class ThreadUnsafeSingletonTest{
	public:
	ThreadUnsafeSingleton* i1 = ThreadUnsafeSingleton::GetInstance();
	ThreadUnsafeSingleton* i2 = ThreadUnsafeSingleton::GetInstance();

	virtual ~ThreadUnsafeSingletonTest() {
		ThreadUnsafeSingleton::Release();
	}

};

class ThreadSafeSingletonTest {
public:
	virtual ~ThreadSafeSingletonTest() {
		ThreadSafeSingletonVer1::Release();
	}
};

TEST(ThreadUnsafeSingletonTest, ThreadUnsafeSingle) {
	ASSERT_EQ(i1->GetNum(), 0);
	ASSERT_EQ(i2->GetNum(), 0);

	i1->SetNum(100);
	ASSERT_EQ(i2->GetNum(), 100);
};

#define N 1000
TEST(ThreadSafeSingletonTest, Version1) {
	long long instance = (long long)ThreadSafeSingletonVer1::GetInstance();

	auto threadFunc = [=]() -> void {
		auto i1 = (long long)ThreadSafeSingletonVer1::GetInstance();
		ASSERT_EQ(i1, instance);
	};

	std::thread th[N];
	for(int i = 0; i < N; ++i){
		th[i] = std::thread(threadFunc);
	}

	for(int i = 0; i < N; ++i){
		th[i].join();
	}
}

TEST(ThreadSafeSingletonTest, Version2) {
	long long instance = (long long)ThreadSafeSingletonVer2::GetInstance();

	auto threadFunc = [=]() -> void {
		auto i1 = (long long)ThreadSafeSingletonVer2::GetInstance();
		ASSERT_EQ(i1, instance);
	};

	std::thread th[N];
	for (int i = 0; i < N; ++i) {
		th[i] = std::thread(threadFunc);
	}

	for (int i = 0; i < N; ++i) {
		th[i].join();
	}
}


TEST(ThreadSafeSingletonTest, Version3) {
	long long instance = (long long)ThreadSafeSingletonVer3::GetInstance();

	auto threadFunc = [=]() -> void {
		auto i1 = (long long)ThreadSafeSingletonVer3::GetInstance();
		ASSERT_EQ(i1, instance);
	};

	std::thread th[N];
	for (int i = 0; i < N; ++i) {
		th[i] = std::thread(threadFunc);
	}

	for (int i = 0; i < N; ++i) {
		th[i].join();
	}
}

TEST(ThreadSafeSingletonTest, Version4) {
	long long instance = (long long)ThreadSafeSingletonVer4::GetInstance();

	auto threadFunc = [=]() -> void {
		auto i1 = (long long)ThreadSafeSingletonVer4::GetInstance();
		ASSERT_EQ(i1, instance);
	};

	std::thread th[N];
	for (int i = 0; i < N; ++i) {
		th[i] = std::thread(threadFunc);
	}

	for (int i = 0; i < N; ++i) {
		th[i].join();
	}
}

TEST(ThreadSafeSingletonTest, Version5) {
	long long instance = (long long)ThreadSafeSingletonVer5::GetInstance();

	auto threadFunc = [=]() -> void {
		auto i1 = (long long)ThreadSafeSingletonVer5::GetInstance();
		ASSERT_EQ(i1, instance);
	};

	std::thread th[N];
	for (int i = 0; i < N; ++i) {
		th[i] = std::thread(threadFunc);
	}

	for (int i = 0; i < N; ++i) {
		th[i].join();
	}
}
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence, 
	// make sure excuted sentence to get the memory dump result.
	_CrtDumpMemoryLeaks();
	return ret;
}