#include "util/testharness.h"
#include "util/basic.h"


namespace CLRS {
	
class EXAMPLE{};

TEST(EXAMPLE, example) {
	ASSERT_EQ(1, 1);
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}