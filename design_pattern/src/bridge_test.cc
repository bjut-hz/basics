#include "util/testharness.h"
#include "util/basic.h"
#include "bridge.h"

namespace DP {
	
class BridgeTest{};

TEST(BridgeTest, All) {
	std::shared_ptr<Abstraction> ab = std::make_shared<RefinedAbstraction>();
	ab->SetImplementor(std::make_shared<ConcreteImplementorA>());
	ab->Operation();

	ab->SetImplementor(std::make_shared<ConcreteImplementorB>());
	ab->Operation();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}