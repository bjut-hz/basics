#include "util/testharness.h"
#include "util/basic.h"


namespace DP {
	
class EXAMPLE{};

TEST(EXAMPLE, example) {
	ASSERT_EQ(1, 1);
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}