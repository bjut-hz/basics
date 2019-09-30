#include "util/testharness.h"
#include "util/basic.h"
#include "decorator.h"


namespace DP {
	
class DecoratorTest{};

TEST(DecoratorTest, All) {
	std::shared_ptr<ConcreteComponent> component = std::make_shared<ConcreteComponent>();

	std::shared_ptr<ConcreteDecoratorA> decorator_a = std::make_shared<ConcreteDecoratorA>();
	std::shared_ptr<ConcreteDecoratorB> decorator_b = std::make_shared<ConcreteDecoratorB>();

	decorator_a->SetComponent(std::dynamic_pointer_cast<Component>(component));
	decorator_b->SetComponent(std::dynamic_pointer_cast<Component>(decorator_a));

	decorator_b->Operation();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}