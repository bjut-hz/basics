#include "util/testharness.h"
#include "util/basic.h"
#include "state.h"

namespace DP {
	
class StateTest{};

TEST(StateTest, All) {
	std::unique_ptr<Context> context = std::make_unique<Context>(std::make_unique<ConcreteStateA>());
	context->Request();
	context->Request();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}