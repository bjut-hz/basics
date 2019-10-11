#include "util/testharness.h"
#include "util/basic.h"
#include "adapter.h"

namespace DP {
	
class AdapterTest{};

TEST(AdapterTest, All) {
	std::shared_ptr<Target> target = std::make_shared<Adapter>();
	target->Request();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}