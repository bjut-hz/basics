#include "util/testharness.h"
#include "util/basic.h"
#include "visitor.h"

namespace DP {
	
class VisitorTest{};

TEST(VisitorTest, All) {
	ObjectStructure o;
	std::shared_ptr<Element> e1 = std::make_shared<ConcreteElementA>();
	std::shared_ptr<Element> e2 = std::make_shared<ConcreteElementB>();
	std::cout << "element1 addr: " << e1.get() << " element2 addr: " << e2.get() << std::endl;

	o.Attach(e1);
	o.Attach(e2);

	ConcreteVisitor1 v1;
	ConcreteVisitor2 v2;

	o.Accept(v1);
	o.Accept(v2);

	o.Detach(e1);
	o.Accept(v1);
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}