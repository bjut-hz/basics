#include "util/testharness.h"
#include "util/basic.h"
#include "template_method.h"
#include <memory>

namespace DP {
	
class TemplateMethodTest{};

TEST(TemplateMethodTest, All) {
	std::shared_ptr<AbstractClass> c = std::make_shared<ConcreteClass>();
	c->TemplateMethod();	
};

} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}