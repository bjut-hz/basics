#include "util/testharness.h"
#include "util/basic.h"
#include "singleton.h"


namespace DP {
class ThreadUnsafeSingletonTest{
	public:
	ThreadUnsafeSingleton* i1 = ThreadUnsafeSingleton::GetInstance();
	ThreadUnsafeSingleton* i2 = ThreadUnsafeSingleton::GetInstance();

	~ThreadUnsafeSingletonTest() {
		ThreadUnsafeSingleton::Release();
	}

};

TEST(ThreadUnsafeSingletonTest, ThreadUnsafeSingle) {
	ASSERT_EQ(i1->GetNum(), 0);
	ASSERT_EQ(i2->GetNum(), 0);

	i1->SetNum(100);
	ASSERT_EQ(i2->GetNum(), 100);


};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence, 
	// make sure excuted sentence to get the memory dump result.
	_CrtDumpMemoryLeaks();
	return ret;
}