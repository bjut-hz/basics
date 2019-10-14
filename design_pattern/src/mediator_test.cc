#include "util/testharness.h"
#include "util/basic.h"
#include "mediator.h"

namespace DP {
	
class MediatorTest{};

TEST(MediatorTest, All) {
	auto m = std::make_shared<ConcreteMediator>();
	auto c1 = std::make_shared<ConcreteColleague1>(std::dynamic_pointer_cast<Mediator>(m));
	auto c2 = std::make_shared<ConcreteColleague2>(std::dynamic_pointer_cast<Mediator>(m));

	m->SetColleague1(c1);
	m->SetColleague2(c2);

	c1->Send("how are you?");
	c2->Send("fine, and you?");
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}