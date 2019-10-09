#include "util/testharness.h"
#include "util/basic.h"
#include "facade.h"

namespace DP {
	
class FacadeTest{};

TEST(FacadeTest, All) {
	Facade facade;
	facade.MethodA();
	facade.MethodB();
};

} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}