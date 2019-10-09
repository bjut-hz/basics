#include "util/testharness.h"
#include "util/basic.h"
#include "prototype.h"

namespace DP {
	
class PrototypeTest{};

TEST(PrototypeTest, All) {
	ConcretePrototype1* p1 = new ConcretePrototype1(100);
	ConcretePrototype1* p2 = static_cast<ConcretePrototype1*>(p1->Clone());

	ASSERT_EQ(p1->id(), p2->id());

	delete p1;
	delete p2;
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}