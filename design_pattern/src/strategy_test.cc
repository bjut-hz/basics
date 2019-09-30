#include "util/testharness.h"
#include "util/basic.h"
#include "strategy.h"


namespace DP {
	
class StrategyTest{};

TEST(StrategyTest, Strategy) {
	std::shared_ptr<IStrategy> strategy = std::make_shared<ConcreteStrategyA>();
	Context context_a(strategy);
	context_a.ContextInterface();

	strategy = std::make_shared<ConcreteStrategyB>();
	Context context_b(strategy);
	context_b.ContextInterface();
};

TEST(StrategyTest, ContextWithFactory) {
	Context context(Context::StrategyType::kA);
	context.ContextInterface();

	Context context_b(Context::kB);
	context_b.ContextInterface();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}